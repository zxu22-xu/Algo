#include "Simple_MC.h"
#include "Random_1.h"
#include <cmath>

#if !defined(_MSC_VER)
using namespace std;
#endif

double SimpleMonteCarlo2(const Payoff& p, double Expiry, double Spot, double Vol, double r, unsigned long NumberOfPaths)
{
	double variance = Vol * Vol * Expiry;
	double rootVariance = sqrt(variance);
	double itoCorrelation = -0.5 * variance;

	double movedSpot = Spot * exp(r * Expiry + itoCorrelation);
	double thisSpot;
	double runningSum = 0;

	for (unsigned long i = 0; i < NumberOfPaths; i++)
	{
		double thisGaussian = GetOneGaussianByBoxMuller();
		thisSpot = movedSpot * exp(rootVariance * thisGaussian);
		double thisPayoff = p(thisSpot);
		runningSum += thisPayoff;
	}

	double mean = runningSum / NumberOfPaths;
	mean *= exp(-r * Expiry);
	return mean;
}