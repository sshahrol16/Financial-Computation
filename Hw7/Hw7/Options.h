#ifndef Options06_h
#define Options06_h
#include "BinModel.h"

class EurOption
{
private:
	int N; //steps to expiry
public:
	void SetN(int N_) { N = N_; }
	//Payoff defined to return 0.0
	//for pedagogical purposes.
	//To use a pure virtual function replace by
	virtual double Payoff(double z, double K) = 0;
	//virtual double Payoff(double z) { return 0.0; }
	//pricing European option
	double PriceByCRR(BinModel Model);
};


class Call : public EurOption
{
private:
	double K; //strike price
public:
	void SetK(double K_) { K = K_; }
	//int GetInputData();
	double Payoff(double z, double K);
};
class Put : public EurOption
{
private:
	double K; //strike price
public:
	void SetK(double K_) { K = K_; }
	//int GetInputData();
	double Payoff(double z, double K);
};


#endif