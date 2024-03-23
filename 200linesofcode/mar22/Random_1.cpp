#include "Random_1.h"
#include <cstdlib>
#include <cmath>

#if !defined(_MSC_VER)

using namespace std;
#endif

double GetOneGaussianBySummation() 
{
	double res = 0;
	for (unsigned long j = 0; j < 12; j++) {
		res += rand() / static_cast<double>(RAND_MAX);
	}
	res -= 6.0;
	return res;
};




double GetOneGaussianByBoxMuller() 
{
	double res;

	double x;
	double y;

	double sizeSquared;

	do {
		x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
		y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
		sizeSquared = x * x + y * y;
	} while (sizeSquared >= 1.0);

	res = x * sqrt(-2 * log(sizeSquared) / sizeSquared);
	return res;
};