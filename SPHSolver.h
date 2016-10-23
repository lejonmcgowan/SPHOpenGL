#pragma once 

#include <list>
#include <cstddef>
#include <vector>

#include "Particle.h"
#include "Kernel.h"
#include "GridManager.h"



using namespace std;

class SPHSolver;

#ifndef _SPH_H_
#define _SPH_H_

struct FluidMaterial 
{

	const float gasConstant;
	const float restDensity;
	const float damping;
	float mu;
	void changeViscosity(float value){mu += value;}
};

class SPHSolver 
{

	const int gridWidth;
	const int gridHeight;
	const int gridDepth;

	const float kernelDistance;
	const float timestep;

	Kernel *kernel;
	GridManager* gridManager;

public:

	SPHSolver(
			float gridWidth,
			float gridHeight,
			float gridDepth,
			float kernelDistance,
			float timestep):
	  gridWidth(gridWidth),
	  gridHeight(gridHeight),
	  gridDepth(gridDepth),
	  kernelDistance(kernelDistance),
	  timestep(timestep)
	  {
	  	kernel = new Kernel();
	  }

	void update();

	void initParticles(vector<Particle *>& particles);

	Eigen::Vector3f gravity;
	Eigen::Vector4f bounds;
	void addGravity(int index, float value){gravity(index) += value;}
	void changeBounds(int index, float delta)
	{
		if(bounds(index) + delta < 0)
		{
			bounds(index) += delta;
			bounds(index + 1) -= delta;
		}
	}

private:
	void addDensities(Particle *particle, Particle *neighbour);

	void sumDensities(GridElement &gridelement, Particle *particle);

	void sumAllDensities(int i, int j, int k, Particle *particle);

	void updateDensities(int i, int j, int k);

	void addForces(Particle *particle, Particle *neighbour);

	void sumForces(GridElement &gridelement, Particle *particle);

	void sumAllForces(int i, int j, int k, Particle *particle);

	void updateForces(int i, int j, int k);

	void updateParticle(Particle *particle);

	void updateParticles(int i, int j, int k);

	void resetParticle(Particle *particle);

	void resetParticles();

	void updateDensities();

	void updateForces();

	void updateParticles();
};

#endif /* _SPH_H_ */

