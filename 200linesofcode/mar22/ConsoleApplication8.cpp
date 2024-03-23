// ConsoleApplication8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Random_1.h"
#include <cmath>
using namespace std;

double SimpleMonteCarlo(double Expiry, double Strike, double Spot, double Vol, double r,
    unsigned long NumberOfPaths)
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
        double thisPayoff = thisSpot - Strike;
        thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
        runningSum += thisPayoff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r * Expiry);
    return mean;
}

int main()
{
    //using the random number generator from Random_1.h
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "\nEnter expiry\n";
    cin >> Expiry;
    cout << "\nEnter strike\n";
    cin >> Strike;
    cout << "\nEnter spot\n";
    cin >> Spot;
    cout << "\nEnter vol\n";
    cin >> Vol;
    cout << "\nEnter r\n";
    cin >> r;
    cout << "\nEnter number of paths\n";
    cin >> NumberOfPaths;

    double res = SimpleMonteCarlo(Expiry, Strike, Spot, Vol, r, NumberOfPaths);
    cout << "The price is: " << res << "\n";

    double tmp;
    cin >> tmp;

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
