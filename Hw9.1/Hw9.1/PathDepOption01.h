#ifndef PathDepOption01_h
#define PathDepOption01_h
#include "BSModel01.h"
class PathDepOption
{
public:
	double T, Price, PricingError, delta, gamma;
	int m;
	double PriceByMC(BSModel Model, long N, double epsilon);
	virtual double Payoff(SamplePath& S) = 0;
	double PriceByVarRedMC(BSModel Model, long N, PathDepOption& CVOption, double epsilon);
	virtual double PriceByBSFormula(BSModel Model) { return 0.0; };
	virtual double DeltaAnalytical(BSModel Model) { return 0.0; };

};

class DifferenceOfOptions : public PathDepOption
{
public:
	PathDepOption* Ptr1;
	PathDepOption* Ptr2;
	DifferenceOfOptions(double T_, int m_, PathDepOption* Ptr1_, PathDepOption* Ptr2_)
	{
		T = T_; m = m_; Ptr1 = Ptr1_; Ptr2 = Ptr2_;
	}
	double Payoff(SamplePath& S)
	{
		return Ptr1->Payoff(S) - Ptr2->Payoff(S);
	}
};


class ArthmAsianCall : public PathDepOption
{
public:
	double K;
	ArthmAsianCall(double T_, double K_, int m_)
	{
		T = T_; K = K_; m = m_;
	}
	double Payoff(SamplePath& S);
};
class EuropeanCall : public PathDepOption
{
public:
	double K;
	EuropeanCall(double T_, double K_, int m_)
	{
		T = T_; K = K_; m = m_;
	}
	double Payoff(SamplePath& s);
};
class EuropeanPut : public PathDepOption
{
public:
	double K;
	EuropeanPut(double T_, double K_, int m_)
	{
		T = T_; K = K_; m = m_;
	}
	double Payoff(SamplePath& s);
};

#endif