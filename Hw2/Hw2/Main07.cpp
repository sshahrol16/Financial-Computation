#include "BinModel01.h"
#include "Options03.h"
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double S0, U, D, R;
	if (GetInputData(S0, U, D, R) == 1) return 1;
	double K;   //strike price
	int N;      	//steps to expiry
	cout << "Enter call option data:" << endl;
	GetInputData(N, K);
	cout << "European call option price = " << PriceByCRR(S0,U,D,R,N,K,CallPayoff)   << endl << endl;
	cout << "European digital call option price = " << PriceByCRR(S0, U, D, R, N, K, DigitalCallPayoff) << endl << endl;
		cout << "Enter put option data:" << endl;
	GetInputData(N, K);
	cout << "European put option price =  " << PriceByCRR(S0, U, D, R, N, K, PutPayoff) << endl << endl;
	cout << "European digital put option price =  " << PriceByCRR(S0, U, D, R, N, K, DigitalPutPayoff) << endl << endl;
	int x;
	cin >> x;
	return 0;
}

/*
Output:
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

European digital call option price = 0.575897

Enter put option data:
Enter steps to expiry N: 8
Enter strike price K:    100

European put option price =  11.4261

European digital put option price =  0.381553


*/

