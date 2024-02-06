#ifndef Options_h
#define Options_h

#include "BinModel.h"

class EurOption {
private:
	int N; 

public: 
	void setN(int N_) { N = N_; }
	virtual double payOff(double z) { return 0.0; }
	double priceByCRR(BinModel Model);

};

class AmOption {
private:
	int N;
public:
	void setN(int N_) { N = N_;}
	virtual double payOff(double z) = 0;
	double priceBySnell(BinModel Model);
};


class Call : public EurOption, public AmOption {
private:
	double K;
public:
	void setK(double K_) { K = K_; }
	int getInputData();
	double payOff(double z);
};

class Put : public EurOption, public AmOption {
private:
	double K;
public:
	void setK(double K_) { K = K_; }
	int getInputData();
	double payOff(double z);

};

//extended function for double digital
class DoubleDigi : public EurOption {
private:
	double K1, K2;
public:
	void setK(double K1_, double K2_) { K1 = K1_; K2 = K2_; } //seems not needed
	int getInputData();
	double payOff(double z);

};

#endif 
