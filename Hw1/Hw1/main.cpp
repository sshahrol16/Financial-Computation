#include "BinModel01.h"
#include "Options01.h"
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	
	double S0, U, D, R;
	if (GetInputData(S0, U, D, R) == 1) return 1;
	double K;   //strike price
	int N;      //steps to expiry
	cout << "Enter call option data:" << endl;
	GetInputData(N, K);
	cout << "European call option price = " << PriceByCRR(S0, U, D, R, N, K) << endl << endl;
	cout << "Price by Factorial = " << PriceByFactorial(S0, U, D, R, N, K) << endl << endl;
	
	
	int x;
	cin >> x;

	return 0;
}

/*
Shahmir Shahrol
HW 1

Outout:
Enter S0: 106
Enter U:  0.15125
Enter D:  -0.13138
Enter R:  0.00545

Input data checked
There is no arbitrage

Enter call option data:
Enter steps to expiry N: 8
Enter strike price K:    100

European call option price = 21.6811

Price by Factorial = 21.6811


*/