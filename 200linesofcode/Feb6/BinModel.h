#ifndef BinModel_h
#define BinModel_h

class BinModel {
private:
	double S0;
	double R;
	double U;
	double D;

public:
	//compute risk-neutral probability here
	double RiskNeutralProb();

	//compute the stock price at Node
	double S(int n, int i); 

	//getting input data
	int getInput();
	double getR();

};

#endif 
