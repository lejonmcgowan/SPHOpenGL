#pragma once

#include <iostream>

#include "Eigen/Dense"
#define EIGEN_DONT_VECTORIZE 
#define EIGEN_DISABLE_UNALIGNED_ARRAY_ASSERT

#define PI 3.141592653589793f

class Kernel
{
public:
	Kernel(){};

	float kernel(Eigen::Vector3f &r,float h);

	Eigen::Vector3f gradientPressureKernel(const Eigen::Vector3f &r, const float h);

	float laplacianViscosityKernel(const Eigen::Vector3f &r, const float h);
};
