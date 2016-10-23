/*All kernel formulas were derived from the following video by AMD:
	https://www.youtube.com/watch?v=SQPCXzqH610
*/
#include "Kernel.h"

//for cleanliness reasons. inline to make it faster
template <typename T>
inline T pow2(T num){return num * num;}
template <typename T>
inline T pow3(T num){return pow2(num) * num;}
template <typename T>
inline T pow6(T num){return pow2(num) * pow3(num);}
template <typename T>
inline T pow9(T num){return pow3(num) * pow3(num);}

float Kernel::kernel(Eigen::Vector3f &r, float h) {
	return 315.0f / (64.0f * PI * pow9(h)) * pow3(pow2(h) - r.squaredNorm());
}

Eigen::Vector3f Kernel::gradientPressureKernel(const Eigen::Vector3f &r, const float h) {
	if (r.squaredNorm() < pow2(0.001f)) {
		return Eigen::Vector3f(0.0f,0.0f,0.0f);
	}

	return -45.0f / (PI * pow6(h)) * pow2(h - r.norm()) * r.normalized();
}

float Kernel::laplacianViscosityKernel(const Eigen::Vector3f &r, const float h) {
	return 45.0f / (PI * pow6(h)) * (h - r.norm());
}