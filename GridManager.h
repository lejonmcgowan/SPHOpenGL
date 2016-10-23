#pragma once

#include <cstddef>
#include <vector>

#include "Particle.h"

using namespace std;

struct GridElement{vector<Particle *> particles;};

class GridManager
{

public:	
	std::vector<GridElement> grids;
	std::vector<GridElement> tempGrids;
	GridManager(int width, int height, int depth, std::vector<Particle *>& allParticles):
	width(width),
	height(height),
	depth(depth)
	{
		int numOfGrids = width * height * depth;
		
		for(int i = 0; i < numOfGrids; i++)
		{
			grids.push_back(GridElement());
			tempGrids.push_back(GridElement());
		}

		for (auto particle: allParticles)
			addToGrid(grids, particle);
	}

	GridElement &getGrid(int i, int j, int k);

	GridElement &getTempGrid(int i, int j, int k);

	void addToGrid(vector<GridElement>& targetGrid, Particle *particle);
	void updateGrid();
	int  gridIndex(float i, float j, float k);
	void insertIntoTempGrid(int i, int j, int k);
private:
	int width;
	int height;
	int depth;
};