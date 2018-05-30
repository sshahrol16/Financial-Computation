#include "Options01.h"
#include "BinModel01.h"
#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n)
{
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

int GetInputData(int& N, double& K)
{
	cout << "Enter steps to expiry N: "; cin >> N;
	cout << "Enter strike price K:    "; cin >> K;
	cout << endl;
	return 0;
}
double CallPayoff(double z, double K)
{
	if (z>K) return z - K;
	return 0.0;
}
double PriceByCRR(double S0, double U, double D, double R, int N, double K)
{
	double q = RiskNeutProb(U, D, R);
	double Price[10];
	for (int i = 0; i <= N; i++)
	{
		Price[i] = CallPayoff(S(S0, U, D, N, i), K);
	}
	for (int n = N - 1; n >= 0; n--)
	{
		for (int i = 0; i <= n; i++)
		{
			Price[i] = (q*Price[i + 1] + (1 - q)*Price[i]) / (1 + R);
		}
	}
	return Price[0];
}

double PriceByFactorial(double S0, double U, double D, double R, int N, double K)
{
	double q = RiskNeutProb(U, D, R);
	double Price = 0;
	int factN = factorial(N);
	for (int i = 0; i <= N; i++)
	{
		Price += (factN / (factorial(i) * factorial(N - i)) * pow(q, i) * pow(1 - q, N - i) * CallPayoff(S(S0, U, D, N, i), K)) / pow(1 + R, N);

	}
	return Price;
}