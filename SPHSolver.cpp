#include "SPHSolver.h"
#include <cstdio>

#include <iostream>

using namespace std;

inline void SPHSolver::addDensities(Particle *particle, Particle *neighbour) 
{
	if (particle->id > neighbour->id) 
	{
		return;
	}

	Eigen::Vector3f r = particle->position - neighbour->position;
	if (r.squaredNorm() > kernelDistance * kernelDistance) 
	{
		return;
	}

    float influence = kernel->kernel(r, kernelDistance);
    particle->density += neighbour->mass * influence;
	neighbour->density += particle->mass * influence;
}

void SPHSolver::sumDensities(GridElement &grid, Particle *particle)
 {
	for (auto otherParticle: grid.particles) {
		addDensities(particle, otherParticle);
	}
}

inline void SPHSolver::sumAllDensities(int i, int j, int k, Particle *particle) 
{
	for (int z = k - 1; z <= k + 1; z++) 
	{
		for (int y = j - 1; y <= j + 1; y++) 
		{
			for (int x = i - 1; x <= i + 1; x++) 
			{
				if (   (x < 0) || (x >= gridWidth)
					|| (y < 0) || (y >= gridHeight)
					|| (z < 0) || (z >= gridDepth)) 
				{
					continue;
				}

				sumDensities(gridManager->getGrid(x, y, z), particle);
			}
		}
	}
}

void SPHSolver::updateDensities(int i, int j, int k) 
{
	GridElement &grid = gridManager->getGrid(i, j, k);

	for (auto particle: grid.particles) 
		sumAllDensities(i, j, k, particle);
}

inline void SPHSolver::addForces(Particle *particle, Particle *neighbour) 
{
	if (particle->id >= neighbour->id) 
		return;

	Eigen::Vector3f r = particle->position - neighbour->position;

	if (r.squaredNorm() > kernelDistance * kernelDistance) 
		return;

	/* Compute the pressure force. */
	Eigen::Vector3f influence = 0.12f * particle->gasConstant
			* ((particle->density - particle->restDensity) + 
			  (neighbour->density - particle->restDensity))
	        * kernel->gradientPressureKernel(r, kernelDistance);

	particle->sumForces += -neighbour->mass / neighbour->density * influence;
	particle->pressure_force += -neighbour->mass / neighbour->density * influence;
	neighbour->sumForces -= -particle->mass / particle->density * influence;
	neighbour->pressure_force -= -particle->mass / particle->density * influence;

	/* Compute the viscosity force. */
	influence = neighbour->viscosity * (neighbour->velocity - particle->velocity)
	         * kernel->laplacianViscosityKernel(r, kernelDistance);

	particle->sumForces += neighbour->mass / neighbour->density * influence;
	particle->viscosity_force += neighbour->mass / neighbour->density * influence;
	neighbour->sumForces -= particle->mass / particle->density * influence;
	neighbour->viscosity_force -= particle->mass / particle->density * influence;

}

void SPHSolver::sumForces(GridElement &grid, Particle *particle) {
	for (auto otherParticle: grid.particles) {
		addForces(particle, otherParticle);
	}
}

void SPHSolver::sumAllForces(int i, int j, int k, Particle *particle) {
	for (int z = k - 1; z <= k + 1; z++) {
		for (int y = j - 1; y <= j + 1; y++) {
			for (int x = i - 1; x <= i + 1; x++) {
				if (   (x < 0) || (x >= gridWidth)
					|| (y < 0) || (y >= gridHeight)
					|| (z < 0) || (z >= gridDepth)) {
					continue;
				}

				sumForces(gridManager->getGrid(x, y, z), particle);
			}
		}
	}
}

void SPHSolver::updateForces(int i, int j, int k) {
	GridElement &grid = gridManager->getGrid(i, j, k);
	for (auto particle: grid.particles) {
		sumAllForces(i, j, k, particle);
	}
}
inline bool outOfBounds(Particle* p, int index, double min, double max)
{
	return p->position(index) < min && p->velocity(index) < 0 || 
		   p->position(index) > max && p->velocity(index) > 0;
}
inline void SPHSolver::updateParticle(Particle *particle) {
	//gravity
	particle->sumForces += particle->density * gravity;

	Eigen::Vector3f acceleration =   particle->sumForces / particle->density
	               - particle->damping * particle->velocity / particle->mass;
	particle->velocity += timestep * acceleration;
	//boundaries
	if(outOfBounds(particle, 0,bounds(0),bounds(1)))
	{
		particle->velocity(0) = -particle->velocity(0) * 0.1;
		if(particle->velocity(0) < 0.1 && particle->velocity(0) > 0)
			particle->velocity(0) = 5.5;
		else if(particle->velocity(0) > -0.1 && particle->velocity(0) < 0)
			particle->velocity(0) = -5.5;
	}
	if(outOfBounds(particle, 1,0,100.25))
		
		particle->velocity(1) = -particle->velocity(1) * 0.001;
	if(outOfBounds(particle, 2,bounds(2),bounds(3)))
	{
		particle->velocity(2) = -particle->velocity(2) * 0.1;

		if(particle->velocity(2) < 0.1 && particle->velocity(2) > 0)
			particle->velocity(2) = 5.5;
		else if(particle->velocity(2) > -0.1 && particle->velocity(2) < 0)
			particle->velocity(2) = -5.5;
	}
	//timestep
	particle->position += timestep * particle->velocity;

}

inline void SPHSolver::resetParticle(Particle *particle) {
	particle->density = 0.0f;
	particle->sumForces = Eigen::Vector3f(0.0f,0.0f,0.0f);
	particle->viscosity_force = Eigen::Vector3f(0.0f,0.0f,0.0f);
	particle->pressure_force = Eigen::Vector3f(0.0f,0.0f,0.0f);
}

void SPHSolver::resetParticles() {
	for (int k = 0; k < gridDepth; k++) {
		for (int j = 0; j < gridHeight; j++) {
			for (int i = 0; i < gridWidth; i++) {
				GridElement &grid = gridManager->getGrid(i, j, k);

				for (auto particle: grid.particles) {
					resetParticle(particle);
				}
			}
		}
	}
}

void SPHSolver::updateDensities() {
	for (int k = 0; k < gridDepth; k++) {
		for (int j = 0; j < gridHeight; j++) {
			for (int i = 0; i < gridWidth; i++) {
				updateDensities(i, j, k);
			}
		}
	}
}

void SPHSolver::updateForces() {
	for (int k = 0; k < gridDepth; k++) {
		for (int j = 0; j < gridHeight; j++) {
			for (int i = 0; i < gridWidth; i++) {
				updateForces(i, j, k);
			}
		}
	}
}

void SPHSolver::updateParticles() {
	
	for (int k = 0; k < gridDepth; k++) {
		for (int j = 0; j < gridHeight; j++) {
			for (int i = 0; i < gridWidth; i++) {
				GridElement &grid = gridManager->getGrid(i, j, k);

				for (auto particle: grid.particles) 
					updateParticle(particle);
			}
		}
	}
}

void SPHSolver::update() {
	resetParticles();

    updateDensities();
    updateForces();

    updateParticles();

	gridManager->updateGrid();
}

void SPHSolver::initParticles(vector<Particle *>& particles) {

	gridManager = new GridManager(gridWidth,gridHeight,gridDepth, particles);

	gravity << 0.0f,-50.0f,0.0f;
	bounds << -3.0f,3.0f,-3.0f,3.0f;
}







