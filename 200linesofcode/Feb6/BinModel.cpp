// BinModel.cpp
// try lambda captures 

#include "BinModel.h"
#include <iostream>
#include <cmath>
#include <algorithm>

double BinModel::RiskNeutralProb() {
	return (R - D)/(U - D);
}

double BinModel::S(int n, int i) {
	return S0 * pow(1 + U, i) * pow(1 + D, n - i);
}

int BinModel::getInput() {
	std::cout << "Input S0: " << std::endl; std::cin >> S0;
	std::cout << "Input U: " << std::endl; std::cin >> U;
	std::cout << "Input D: " << std::endl; std::cin >> D;
	std::cout << "Input R: " << std::endl; std::cin >> R;
	std::cout << std::endl;

	//check if input is reasonable
	if (S0 <= 0.0 || U <= -1.0 || D <= -1.0 || U <= D || R <= -1.0) {
		std::cout << "Illegal data input" << std::endl;
		std::cout << "Program terminated" << std::endl;
		return 1;
	}

	//check for arbitrage conditions
	if (R >= U || R <= D) {
		std::cout << "Arbitrage exists" << std::endl;
	}
	else std::cout << "There is no arbitrage" << std::endl;

	return 0;
	

}

double BinModel::getR() { return R; }



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
