#include "BinModel02.h"
#include <iostream>
#include "PathDepOption01.h"
#include "GmtrAsianCall.h"
#include "EurCall.h"

using namespace std;
int main()
{

	cout << "Hw1: " << endl;
	double S0 = 106, r = 0.058, sigma = 0.46;
	BSModel Model(S0, r, sigma);
	double T = 9.0 / 12.0, K = 100.0;
	int m = 100;
	long N = 30000;
	double epsilon = 0.0001;
	BSModel ModelCall(S0, r, sigma);
	EuropeanCall OptionCall(T, K, m);
	cout << "European Call Price = " << OptionCall.PriceByMC(ModelCall, N, epsilon) << endl;
	BSModel ModelPut(S0, r, sigma);
	EuropeanPut OptionPut(T, K, m);
	cout << "European Put Price = " << OptionPut.PriceByMC(ModelPut, N, epsilon) << endl;

	cout << endl << "Hw2: " << endl;
	S0 = 100, r = 0.03, sigma = 0.2;
	T = 1.0 / 12.0, K = 100.0;
	m = 30, N = 30000, epsilon = 0.001;
	BSModel ModelAsianCall(S0, r, sigma);
	ArthmAsianCall AsianOption(T, K, m);
	cout << "Asian Call Price = " << AsianOption.PriceByMC(ModelAsianCall, N, epsilon) << endl;
	cout << "Pricing Error = " << AsianOption.PricingError << endl;
	cout << "delta = " << AsianOption.delta << endl;
	cout << "gamma = " << AsianOption.gamma << endl;

	cout << endl << "HW3: " << endl;
	BSModel ModelG(S0, r, sigma);
	ArthmAsianCall Option(T, K, m);
	GmtrAsianCall  CVOption(T, K, m);
	Option.PriceByVarRedMC(ModelG, N, CVOption, epsilon);
	cout << "Arithmetic call price = " << Option.Price << endl << "Error = " << Option.PricingError << endl << "Delta = " << Option.delta << endl;
	cout << endl;
	Option.PriceByMC(ModelG, N, epsilon);
	cout << "Price by direct MC = " << Option.Price << endl << "MC Error = " << Option.PricingError << endl << "Delta = " << Option.delta << endl;

	int x;
	cin >> x;
}

/*
Output:

Hw1:
European Call Price = 21.8189
European Put Price = 11.3041

Hw2:
Asian Call Price = 1.43199
Pricing Error = 0.0120179
delta = 0.525918
gamma = 0.116318

HW3:
Arithmetic call price = 1.42591
Error = 0.000134295
Delta = 0.520064

Price by direct MC = 1.41622
MC Error = 0.0119848
Delta = 0.527478

*/