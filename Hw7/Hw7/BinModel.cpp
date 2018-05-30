#include "BinModel.h"
#include <iostream>
#include <cmath>
using namespace std;

double BinModel::RiskNeutProb()
{
	return (R - D) / (U - D);
}
double BinModel::S(int n, int i)
{
	return S0*pow(1 + U, i)*pow(1 + D, n - i);
}
int BinModel::GetInputData()
{
	//entering data
	cout << "Enter S0: "; cin >> S0;
	cout << "Enter r:  "; cin >> r;
	cout << "Enter sigma:  "; cin >> sigma;
	cout << "Enter T:  "; cin >> T;
	cout << "Enter K:  "; cin >> K;
	cout << "Enter N:  "; cin >> N;
	cout << endl;	
	double h = T / N;
	U = exp((r - sigma*sigma / 2)*h + sigma*sqrt(h)) - 1;
	D = exp((r - sigma*sigma / 2)*h - sigma*sqrt(h)) - 1;
	R = exp(r*h)-1;

	return 1;
}
double BinModel::GetU() 
{
	return U;
}
double BinModel::GetR()
{
	return R;
}
double BinModel::GetD()
{
	return D;
}