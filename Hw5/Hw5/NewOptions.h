#ifndef NewOptions_h
#define NewOptions_h
#include "BinModel02.h"
#include "Options6.h"

class Strangle : public EurOption
{
private:
	double K1, K2;
public:
	void SetK(double K1_, double K2_);
	int GetInputData();
	double Payoff(double z);
};

class Butterfly : public EurOption
{
private:
	double K1, K2;
public:
	void SetK(double K1_, double K2_);
	int GetInputData();
	double Payoff(double z);
};
#endif