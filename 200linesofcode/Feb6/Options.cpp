#include "Options.h"
#include "BinModel.h"
#include <iostream>
#include <cmath>
#include <vector>

double EurOption::priceByCRR(BinModel Model) {
	double q = Model.RiskNeutralProb();
	std::vector<double> Price(N + 1);
	double* Price = new double[N + 1]; //need dynamic memory alloc
	for (int i = 0; i <= N; i++) {
		Price[i] = payOff(Model.S(N, i));
	}
	for (int n = N - 1; n >= 0; n--) {
		for (int i = 0; i <= n; i++) {
			Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + Model.getR());
		}
	}
	return Price[0];
}


double AmOption::priceBySnell(BinModel Model) {
	double q = Model.RiskNeutralProb();
	std::vector<double> Price(N + 1);
	double ContVal;
	for (int i = 0; i <= N; i++) {
		Price[i] = payOff(Model.S(N, i));
	}
	for (int n = N - 1; n >= 0; n--) {
		for (int i = 0; i <= n; i++) {
			ContVal = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + Model.getR());
			Price[i] = payOff(Model.S(N, i));
			if (ContVal > Price[i]) Price[i] = ContVal;
		}
	}
	return Price[0];

}

int Call::getInputData() {
	std::cout << "Enter Call Option Data: " << std::endl;
	int N;
	std::cout << "Enter steps to expiry N: " << std::endl; std::cin >> N;
	EurOption::setN(N); AmOption::setN(N);
	std::cout << "Enter strike price K: "; std::cin >> K;
	std::cout << std::endl;
	return 0;
}

double Call::payOff(double z) {
	if (z > K) return (z - K);
	else return 0.0;
}

int Put::getInputData() {
	std::cout << "Enter put option data: " << std::endl;
	int N;
	std::cout << "Enter steps to expiry N: " << std::endl; std::cin >> N;
	EurOption::setN(N); AmOption::setN(N);
	std::cout << "Enter strike price K: " << std::endl; std::cin >> K;
	std::cout << std::endl;
	return 0;
}

double Put::payOff(double z) {
	if (z < K) return (K - z);
	else return 0.0;
}

int DoubleDigi::getInputData() {
	std::cout << "Enter double digital option data: " << std::endl;
	int N;
	std::cout << "Enter steps to expiry N: " << std::endl; std::cin >> N;
	EurOption::setN(N);
	std::cout << "Enter strike price K1: " << std::endl; std::cin >> K1;
	std::cout << "Enter strike price K2: " << std::endl; std::cin >> K2;
	std::cout << std::endl;
	return 0;
}

double DoubleDigi::payOff(double z) {
	//should add a line here to identify bigger strike and smaller strike
	//return (num1 > num2) ? num1 : num2 
	if (K1 < z && z < K2) return 1.0;
	else return 0.0;
}

