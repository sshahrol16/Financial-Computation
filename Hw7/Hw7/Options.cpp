#include "Options.h"
#include "BinModel.h"
#include <iostream>
#include <cmath>
using namespace std;
double EurOption::PriceByCRR(BinModel Model)
{
	double q = Model.RiskNeutProb();
	SetN(Model.GetN());
	double Price[20];
	for (int i = 0; i <= N; i++) { Price[i] = Payoff(Model.S(N, i), Model.GetK()); }
	for (int n = N - 1; n >= 0; n--)
	{
		for (int i = 0; i <= n; i++)
		{
			Price[i] = (q*Price[i + 1] + (1 - q)*Price[i]) / (1 + Model.GetR());
		}
	}
	return Price[0];
}
/*
int Call::GetInputData()
{
	cout << "Enter call option data:" << endl;
	int N;
	cout << "Enter steps to expiry N: "; cin >> N;
	SetN(N);
	cout << "Enter strike price K:    "; cin >> K;
	cout << endl;
	return 0;
}
*/
double Call::Payoff(double z, double K)
{
	if (z>K) return z - K;
	return 0.0;
}
/*
int Put::GetInputData()
{
	cout << "Enter put option data:" << endl;
	int N;
	cout << "Enter steps to expiry N: "; cin >> N;
	SetN(N);
	cout << "Enter strike price K:    "; cin >> K;
	cout << endl;
	return 0;
}
*/
double Put::Payoff(double z, double K)
{
	if (z<K) return K - z;
	return 0.0;
}
