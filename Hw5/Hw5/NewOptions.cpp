#include "NewOptions.h"
#include "Options6.h"
#include "BinModel02.h"
#include <iostream>
#include <cmath>
using namespace std;


void Butterfly::SetK(double K1_, double K2_)
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
int Butterfly::GetInputData()
{
	cout << "Enter put option data:" << endl;
	int N;
	cout << "Enter steps to expiry N: "; cin >> N;
	SetN(N);
	double K1_, K2_;
	cout << "Enter strike price K1:  "; cin >> K1_;
	cout << "Enter strike price K2:  "; cin >> K2_;
	cout << endl;
	SetK(K1_, K2_);
	return 0;
}
double Butterfly::Payoff(double z)
{
	if (z > K1 && z <= (K1+K2)/2) { return z-K1; }
	if (z <= K2 && z > (K1+K2)/2) { return K2-z; }
	return 0;

}

void Strangle::SetK(double K1_, double K2_)
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
int Strangle::GetInputData()
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
double Strangle::Payoff(double z)
{
	if (z < K1) { return K1 - z; }
	if (z > K2) { return z - K2; }
	return 0;

}