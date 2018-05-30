#include "Options6.h"
#include "BinModel02.h"
#include <iostream>
#include <cmath>
using namespace std;

double EurOption::PriceByCRR(BinModel Model)
{
	double q = Model.RiskNeutProb();
	double Price[20];
	for (int i = 0; i <= N; i++) { Price[i] = Payoff(Model.S(N, i)); }
	for (int n = N - 1; n >= 0; n--)
	{
		for (int i = 0; i <= n; i++)
		{
			Price[i] = (q*Price[i + 1] + (1 - q)*Price[i]) / (1 + Model.GetR());
		}
	}
	return Price[0];
}

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
double Call::Payoff(double z)
{
	if (z>K) return z - K;
	return 0.0;
}

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
double Put::Payoff(double z)
{
	if (z<K) return K - z;
	return 0.0;
}

void BullSpread::SetK(double K1_, double K2_)
{
	while (K2_ < K1_) {
		cout << "K1 must be smaller than K2" << endl;
		cout << "Enter new K1: ";
		cin >> K1_;
		cout << "Enter new K2: ";
		cin >> K2_;
	}
	K1 = K1_;
	K2 = K2_;
}
int BullSpread::GetInputData()
{
	cout << "Enter put option data:" << endl;
	int N;
	cout << "Enter steps to expiry N: "; cin >> N;
	SetN(N);
	double K1_, K2_;
	cout << "Enter strike price K1:    "; cin >> K1_;
	cout << "Enter strike price K2:    "; cin >> K2_;
	cout << endl;
	SetK(K1_, K2_);
	return 0;
}
double BullSpread::Payoff(double z)
{
	//cout << "K1: " << K1 << " K2: " << K2;
	if (z <= K1) { return 0; }
	if (K1 < z && z < K2) { return z - K1; }
	if (z >= K2) { return K2 - K1; }

}

void BearSpread::SetK(double K1_, double K2_)
{
	while (K2_ < K1_) {
		cout << "K1 must be smaller than K2" << endl;
		cout << "Enter new K1: ";
		cin >> K1_;
		cout << "Enter new K2: ";
		cin >> K2_;
	}
	K1 = K1_;
	K2 = K2_;
}
int BearSpread::GetInputData()
{
	cout << "Enter put option data:" << endl;
	int N;
	cout << "Enter steps to expiry N: "; cin >> N;
	SetN(N);
	double K1_, K2_;
	cout << "Enter strike price K1:    "; cin >> K1_;
	cout << "Enter strike price K2:    "; cin >> K2_;
	cout << endl;
	SetK(K1_, K2_);
	return 0;
}
double BearSpread::Payoff(double z)
{
	//cout << "K1: " << K1 << " K2: " << K2;
	if (z >= K2) { return 0; }
	if (K1 < z && z < K2) { return K2 - z; }
	if (z <= K1) { return K2 - K1; }

}