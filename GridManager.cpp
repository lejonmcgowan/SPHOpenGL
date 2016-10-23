#include "GridManager.h"

void GridManager::addToGrid(vector<GridElement>& targetGrid, Particle *particle) {
	float i = particle->position(0);
	float j = particle->position(1);
	float k = particle->position(2);
	targetGrid[gridIndex(i, j, k)].particles.push_back(particle);
}

int GridManager::gridIndex(float i, float j, float k) {
	if(i > 0)
	{
		if(j > 0)
		{
			if(k > 0)
				return 0;
			else
				return 4;
		}
		else
		{
			if(k > 0)
				return 3;
			else
				return 7;
		}
	}
	else
	{
		if(j > 0)
		{
			if(k > 0)
				return 1;
			else
				return 5;
		}
		else
		{
			if(k > 0)
				return 2;
			else
				return 6;
		}	
	}
}

void GridManager::insertIntoTempGrid(int i, int j, int k) {
	GridElement &grid = getGrid(i, j, k);

	for (auto particle: grid.particles) {
		addToGrid(tempGrids, particle);
	}
}

GridElement &GridManager::getGrid(int i, int j, int k) {
	return grids[gridIndex(i, j, k)];
}

GridElement &GridManager::getTempGrid(int i, int j, int k) {
	return tempGrids[gridIndex(i, j, k)];
}

void GridManager::updateGrid() {
	for (int k = 0; k < depth; k++) {
		for (int j = 0; j < height; j++) {
			for (int i = 0; i < width; i++) {
				insertIntoTempGrid(i, j, k);
				getGrid(i, j, k).particles.clear();
			}
		}
	}

	/* Swap the grids. */
	swap(grids, tempGrids);
}