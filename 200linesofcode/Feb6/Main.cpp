//Testing file for Options and BinModel files

#include "BinModel.h"
#include "Options.h"

#include <iostream>

int main() {
	BinModel Model;
	

	if (Model.getInput() == 1) return 1;

	Call Option1;
	Option1.getInputData();
	std::cout << "Price of the option if it is European Call: " << Option1.priceByCRR(Model);
	std::cout << "Price of the option if it is American Call: " << Option1.priceBySnell(Model);
	
	std::cout << std::endl;

	Put Option2; 
	Option2.getInputData();
	std::cout << "Price of the option if it is European Put: " << Option2.priceByCRR(Model);
	std::cout << "Price of the option if it is American Put: " << Option2.priceBySnell(Model);
	
	std::cout << std::endl;



	DoubleDigi Option3;
	Option3.getInputData();
	std::cout << "Price of the double knock-out digital option: " << Option3.priceByCRR(Model);

	return 0;
}