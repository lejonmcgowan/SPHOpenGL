#ifdef __APPLE__
#include <GLUT/glut.h>
#endif
#ifdef __unix__
#include <GL/glut.h>
#endif
#ifdef _WIN32
#define GLFW_INCLUDE_GLCOREARB
#include <GL/glew.h>
#include <cstdlib>
#include <glut.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Eigen/Dense"
#include "GLSL.h"
#include "Program.h"
#include "Camera.h"
#include "MatrixStack.h"
#include "Texture.h"
#include "HUD.h"
#include "SPHSolver.h"

#define WIDTH		2 //HACKED TOGETHER. don't touch yet
#define HEIGHT		2
#define DEPTH		2

using namespace std;

int width = 1;
int height = 1;
bool keyToggles[256] = {false};
Camera camera;
Program prog;
Program progSimple;
Texture texture;
vector<Particle *> particles;
float t;
float tPrev;
float h;
bool gravType = true;
int currentId;
int NUM_PARTICLES = 200;
float time_step = 0.01;

SPHSolver solver(WIDTH, HEIGHT, DEPTH, 1.5f, time_step);

void loadScene()
{
	t = 0.0f;
	tPrev = 0.0f;
	h = 0.01f;
	
	camera.setTranslations(Eigen::Vector3f(0.0f, 0.0f, 5.0f));
	texture.setFilename("alpha.jpg");
	progSimple.setShaderNames("simple_vert.glsl", "simple_frag.glsl");
	prog.setShaderNames("particle_vert.glsl", "particle_frag.glsl");
	
	for(int i = 0; i < NUM_PARTICLES; ++i) {
		Particle *p = new Particle(i,1000.0f, 0.1f, 1.2f,2.0f);
		particles.push_back(p);
		p->setProgram(&prog);
		p->setKeyToggles(keyToggles);
		p->load();
		currentId = i;
	}
	currentId++;

	solver.initParticles(particles);
}

void initGL()
{
	// Set background color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Enable z-buffer test
	glEnable(GL_DEPTH_TEST);
	// Enable alpha blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	texture.init();
	
	progSimple.init();
	progSimple.addUniform("P");
	progSimple.addUniform("MV");
	
	prog.init();
	prog.addUniform("P");
	prog.addUniform("MV");
	prog.addAttribute("vertPos");
	prog.addAttribute("vertTex");
	prog.addUniform("radius");
	prog.addUniform("alphaTexture");
	prog.addUniform("color");
	
	for(int i = 0; i < (int)particles.size(); ++i) {
		particles[i]->initBuffers();
	}
	
	GLSL::checkVersion();
}

void reshapeGL(int w, int h)
{
	// Set view size
	width = w;
	height = h;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	float aspect = w/(float)h;
	camera.setPerspective(aspect, 45.0f/180.0f*M_PI, 0.1f, 100.0f);
	HUD::setWidthHeight(w, h);
}

// Sort particles by their z values in camera space
class ParticleSorter {
public:
	bool operator()(const Particle *p0, const Particle *p1) const
	{
		// Particle positions in world space
		const Eigen::Vector3f &x0 = p0->getPosition();
		const Eigen::Vector3f &x1 = p1->getPosition();
		// Particle positions in camera space
		float z0 = V.row(2) * Eigen::Vector4f(x0(0), x0(1), x0(2), 1.0f);
		float z1 = V.row(2) * Eigen::Vector4f(x1(0), x1(1), x1(2), 1.0f);
		return z0 < z1;
	}
	
	Eigen::Matrix4f V; // current camera matrix
};
ParticleSorter sorter;

void drawGL()
{
	// Clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// Apply camera transforms
	MatrixStack P, MV;
	camera.applyProjectionMatrix(&P);
	camera.applyViewMatrix(&MV);
	
	// Draw grid
	progSimple.bind();
	glUniformMatrix4fv(progSimple.getUniform("P"), 1, GL_FALSE, P.topMatrix().data());
	glUniformMatrix4fv(progSimple.getUniform("MV"), 1, GL_FALSE, MV.topMatrix().data());
	glLineWidth(2.0f);
	int gridSize = 10;
	float x0 = -5.0f;
	float x1 = 5.0f;
	float z0 = -5.0f;
	float z1 = 5.0f;
	glColor3f(0.8f, 0.8f, 0.8f);
	glBegin(GL_LINE_LOOP);
	glVertex3f(x0, 0.0f, z0);
	glVertex3f(x1, 0.0f, z0);
	glVertex3f(x1, 0.0f, z1);
	glVertex3f(x0, 0.0f, z1);
	glEnd();
	glLineWidth(1.0f);
	glBegin(GL_LINES);
	for(int i = 1; i < gridSize; ++i) {
		if(i == gridSize/2) {
			glColor3f(0.8f, 0.8f, 0.8f);
		} else {
			glColor3f(0.2f, 0.2f, 0.2f);
		}
		float x = x0 + i / (float)gridSize * (x1 - x0);
		glVertex3f(x, 0.0f, z0);
		glVertex3f(x, 0.0f, z1);
	}
	for(int i = 1; i < gridSize; ++i) {
		if(i == gridSize/2) {
			glColor3f(0.8f, 0.8f, 0.8f);
		} else {
			glColor3f(0.2f, 0.2f, 0.2f);
		}
		float z = z0 + i / (float)gridSize * (z1 - z0);
		glVertex3f(x0, 0.0f, z);
		glVertex3f(x1, 0.0f, z);
	}
	glEnd();
	progSimple.unbind();
	
	// Sort the particles by Z
	sorter.V = MV.topMatrix();
	sort(particles.begin(), particles.end(), sorter);
	
	// Draw particles
	prog.bind();
	texture.bind(prog.getUniform("alphaTexture"), 0);
	glUniformMatrix4fv(prog.getUniform("P"), 1, GL_FALSE, P.topMatrix().data());
	MV.pushMatrix();
	for(int i = 0; i < (int)particles.size(); ++i) {
		particles[i]->draw(&MV);
	}
	MV.popMatrix();
	texture.unbind();
	prog.unbind();
	
	// Draw stats
	char str[256];
	sprintf(str, "gravity: (%.2f, %.2f, %.2f)", solver.gravity(0),solver.gravity(1),solver.gravity(2));
	char str2[256];
	sprintf(str2, "boundaries: (%.2f, %.2f) , (%.2f,%.2f)", solver.bounds(0),solver.bounds(1),
														solver.bounds(2),solver.bounds(3));
	glColor4f(0, 1, 0, 1);
	HUD::drawString(10, 10, str);
	HUD::drawString(10, 40, str2);

	// Double buffer
	glutSwapBuffers();
}

void mouseGL(int button, int state, int x, int y)
{
	int modifiers = glutGetModifiers();
	bool shift = modifiers & GLUT_ACTIVE_SHIFT;
	bool ctrl  = modifiers & GLUT_ACTIVE_CTRL;
	bool alt   = modifiers & GLUT_ACTIVE_ALT;
	camera.mouseClicked(x, y, shift, ctrl, alt);
}

void mouseMotionGL(int x, int y)
{
	camera.mouseMoved(x, y);
}

void keyboardGL(unsigned char key, int x, int y)
{
	keyToggles[key] = !keyToggles[key];
	switch(key) {
		case 27:
			// ESCAPE
			exit(0);
			break;
		case 'x':
			solver.addGravity(0,5);
			break;
		case 'X':
			solver.addGravity(0,-5);
			break;
		case 'y':
			solver.addGravity(1,5);
			break;
		case 'Y':
			solver.addGravity(1,-5);
			break;
		case 'z':
			solver.addGravity(2,5);
			break;
		case 'Z':
			solver.addGravity(2,-5);
			break;
		case 'w':
			solver.changeBounds(0,-0.1f);
			break;
		case 'a':
			solver.changeBounds(2,0.1f);
			break;
		case 's':
			solver.changeBounds(0,0.1f);
			break;
		case 'd':
			solver.changeBounds(2,-0.1f);
			break;
	}
}
void drawTimerGL(int value)
{
	// Elapsed time
	float tCurr = 0.001f*glutGet(GLUT_ELAPSED_TIME); // in seconds
	float dt = (tCurr - tPrev);
	if(keyToggles[' ']) {
		solver.update();
		t += dt;
	}
	tPrev = tCurr;
	glutPostRedisplay();
	glutTimerFunc(20, drawTimerGL, 0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	if(argc > 1)
		NUM_PARTICLES = atoi(argv[1]);
	if(argc > 2)
		time_step = atof(argv[2]);
	glutInitWindowSize(1000, 1000);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Your Name");
	glutMouseFunc(mouseGL);
	glutMotionFunc(mouseMotionGL);
	glutKeyboardFunc(keyboardGL);
	glutReshapeFunc(reshapeGL);
	glutDisplayFunc(drawGL);
	glutTimerFunc(20, drawTimerGL, 0);
	loadScene();
	initGL();
	keyToggles['g'] = 1;
	keyToggles['f'] = 1;
	glutMainLoop();
	return 0;
}
