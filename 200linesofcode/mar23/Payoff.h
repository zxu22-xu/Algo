#ifndef Payoff_H
#define Payoff_H

class Payoff {
public:
	enum OptionType {call, put};
	Payoff(double Strike_, OptionType TheOptionsType_);
	double operator() (double Spot) const;

private:
	double Strike;
	OptionType TheOptionsType;
};

#endif
