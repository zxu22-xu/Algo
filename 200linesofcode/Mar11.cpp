// ConsoleApplication7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "matplotlibcpp.h"
#include "BSModel.h"
#include "Eurcall.h"
#include "GeoAsianOpt.h"
#include "PathDependentOption.h"
#include <Python.h>
#include <vector>
#include <cmath>
#include <corecrt_math_defines.h>

namespace plt = matplotlibcpp;

int main()
{
    //std::cout << "Hello World!\n";
    int n = 5000; 
    std::vector<double> x(n), y(n), z(n), w(n, 2);

    //test MC
    double S0 = 100, r = 0.03, sigma = 0.02;
    BSModel Model(S0, r, sigma);
    double T = 1.0 / 12.0;
    double K = 100.0;
    int m = 30;
    ArthmAsianCall Option(T, K, m);
    SamplePath S(m);
    long N = 30000; //number of simulations

    plt::figure_size(1200, 700);

    for (int i = 0; i < N; ++i) 
    {
        Model.GenerateSamplePath(T, m, S);
        plt::plot(S);
    }
        
        
    
   



    for (int i = 0; i < n; ++i) {
        x.at(i) = i * i;
        y.at(i) = sin(2*M_PI*i/360.0);
        z.at(i) = log(i);
    }

    
    
    //plt::plot(x, w, "r--");
    //plt::plot(x, z, { {"label", "log(x)"} });
    //plt::xlim(0, 1000 * 1000);
    plt::title("Simulated Path");
    //plt::legend();
    
    plt::save("./basic.png");
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
