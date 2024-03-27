// DuffyApplications1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include "Lattice.h"
double price(double K, double T, double S, double sig, double r, double H, int N)
{
	//initialize coefficients based on the Trigeorgis approach
	//N = number of intervals
	double dt = T / N;
	double nu = r - 0.5 * sig * sig;

	//Up and down jumps
	double dxu = std::sqrt(sig * sig * dt + (nu * dt) * (nu * dt));
	double dxd = -dxu;

	//Corresponding probabilities 
	double pu = 0.5 + 0.5 * (nu * dt / dxu);
	double pd = 1.0 - pu;

	//Precompute constants
	double disc = std::exp(-r * dt);
	double dpu = disc * pu;
	double dpd = disc * pd;
	double edxud = std::exp(dxu - dxd);
	double edxd = std::exp(dxd);

	//Initialize asset prices
	std::vector<double> St(N + 1);
	St[0] = S * std::exp(N * dxd);

	for (std::size_t j = 1; j < St.size(); ++j)
	{
		St[j] = edxud * St[j - 1];
	}

	//Option value at maturity (t = N)
	std::vector<double> C(N + 1);
	for (std::size_t j = 0; j < C.size(); ++j)
	{
		if (St[j] > H)
		{
			C[j] = std::max<double>(St[j] - K, 0.0);
		}
		else
		{
			C[j] = 0.0;
		}
	}

	//Backwards induction phase
	for (int i = N - 1; i >= 0; --i)
	{
		for (std::size_t j = 0; j <= i; ++j)
		{
			St[j] /= edxd;


			if (St[j] > H)
			{
				C[j] = dpd * C[j] + dpu * C[j + 1];
			}

			else
			{
				C[j] = 0.0;
			}
		}
	}

	//Early exercise down and out call
	return C[0];


}

int main()
{
    double K = 100.0;
    double S = 100.0;
    double T = 1.0;
    double r = 0.06;
    double q = 0.0;
    double sig = 0.2;

    int N = 3;

    double H = 95;
    double OptionPrice = price(K, T, S, sig, r, H, N);

    std::cout << "Price of American down-and-out call option: " << OptionPrice << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
