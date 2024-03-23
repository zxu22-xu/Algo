#include "Payoff.h"
#include <minmax.h>

Payoff::Payoff(double Strike_, OptionType TheOptionType_) : Strike(Strike_), TheOptionsType(TheOptionType_)
{}

double Payoff::operator() (double Spot) const
{
	switch (TheOptionsType)
	{
	case call:
		return max(Spot - Strike, 0.0);
	case put:
		return max(Strike - Spot, 0.0);
	default:
		throw("unknown option type found");
	}
}