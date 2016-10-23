#pragma once
#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#define EIGEN_DONT_VECTORIZE 
#define EIGEN_DISABLE_UNALIGNED_ARRAY_ASSERT

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
#include <vector>
#include "Eigen/Dense"

class MatrixStack;
class Program;
class Texture;

class Particle
{
public:
	Particle(int id,float gasConstant,float viscosity,float restDensity,float damping);
	virtual ~Particle();
	void load();
	void setProgram(Program *p) { prog = p; }
	void setKeyToggles(const bool *k) { keyToggles = k; }
	void init();
	void initBuffers();
	void draw(MatrixStack *MV) const;
	const Eigen::Vector3f& getPosition() const { return position; };
	const Eigen::Vector3f& getVelocity() const { return velocity; };
	const bool *keyToggles;
	
	//particle properties. 
	float mass; // mass
	float damping; // viscous damping
	float density;
	float restDensity;
	float gasConstant;
	float viscosity;
	Eigen::Vector3f pressure_force;
	Eigen::Vector3f position; // position
	Eigen::Vector3f velocity; // velocity
	float radius;
	Eigen::Vector3f sumForces; 
	Eigen::Vector3f viscosity_force;
	int id;
private:
	
	float r = 30 / 255.0f;
	float g = 90 / 255.0f;
	float b = 180 / 255.0f;
	float incr = 0.1;
	
	float lifespan; // how long this particle lives
	float tEnd;     // time this particle dies
	Eigen::Vector4f color;
	std::vector<float> posBuf;
	std::vector<float> texBuf;
	std::vector<unsigned int> indBuf;
	GLuint posBufID;
	GLuint texBufID;
	GLuint indBufID;
	Program *prog;
	
	bool outOfBounds(int index, double min, double max);
};

#endif
