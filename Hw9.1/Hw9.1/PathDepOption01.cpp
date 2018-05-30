#include "PathDepOption01.h"
#include <cmath>
#include <iostream>
void Rescale(SamplePath& S, double x)
{
	int m = S.size();
	for (int j = 0; j < m; j++) S[j] = x*S[j];
}
double PathDepOption::PriceByMC(BSModel Model, long N, double epsilon)
{
	double H = 0.0, Hsq = 0.0, HepsPlus = 0.0, HepsMinus = 0.0, Min = 0.0;
	SamplePath S(m);
	for (long i = 0; i<N; i++)
	{
		Model.GenerateSamplePath(T, m, S);
		H = (i / (i + 1.0))*H + Payoff(S) / (i + 1.0);
		Hsq = (i / (i + 1.0))*Hsq + pow(Payoff(S), 2.0) / (i + 1.0);
		Rescale(S, 1.0 + epsilon);
		HepsPlus = (i / (i + 1.0))*HepsPlus + Payoff(S) / (i + 1.0);
		Rescale(S, (1.0 - epsilon) / (1 + epsilon));
		Min = (i / (i + 1.0))*Min + Payoff(S) / (i + 1.0);

	}
	
	Price = exp(-Model.r*T)*H;
	PricingError = exp(-Model.r*T)*sqrt(Hsq - H*H) / sqrt(N - 1.0);
	delta = exp(-Model.r*T)*(HepsPlus - H) / (Model.S0*epsilon);
	gamma = exp(-Model.r*T)*(HepsPlus - 2 * H + Min) / pow(Model.S0*epsilon, 2);
	return Price;
}
double PathDepOption::PriceByVarRedMC(BSModel Model, long N, PathDepOption& CVOption, double epsilon)
{
	DifferenceOfOptions VarRedOpt(T, m, this, &CVOption);
	Price = VarRedOpt.PriceByMC(Model, N, epsilon) + CVOption.PriceByBSFormula(Model);
	PricingError = VarRedOpt.PricingError;
	delta = VarRedOpt.delta + CVOption.DeltaAnalytical(Model);
	return Price;
}

double ArthmAsianCall::Payoff(SamplePath& S)
{
	double Ave = 0.0;
	for (int k = 0; k<m; k++) Ave = (k / (k + 1.0))*Ave + S[k] / (k + 1.0);
	if (Ave<K) return 0.0;
	return Ave - K;
}

double EuropeanCall::Payoff(SamplePath& S)
{
	if (S[m-1]<K) return 0.0;
	return S[m-1] - K;
}

double EuropeanPut::Payoff(SamplePath& S)
{
	if (K < S[m - 1]) return 0.0;
	return K - S[m - 1];
}

