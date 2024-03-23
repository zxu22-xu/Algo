#ifndef SIMPLE_MC
#define SIMPLE_MC

#include "Payoff.h"

double SimpleMonteCarlo2(const Payoff& p_, double Expiry, double Spot, double Vol, double r, unsigned long NumberOfPaths);

#endif