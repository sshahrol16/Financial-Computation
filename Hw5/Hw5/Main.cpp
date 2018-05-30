#include "BinModel02.h"
#include "Options6.h"
#include "DoubleDigitOpt.h"
#include "NewOptions.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	BinModel Model;
	if (Model.GetInputData() == 1) return 1;
	
	Call Option1;
	Option1.GetInputData();
	cout << "European call option price = " << Option1.PriceByCRR(Model) << endl << endl;
	Put Option2;
	Option2.GetInputData();
	cout << "European put option price = " << Option2.PriceByCRR(Model) << endl << endl;
	/*
	BullSpread Option3;
	Option3.GetInputData();
	cout << "European bull spread price = " << Option3.PriceByCRR(Model) << endl << endl;
	BearSpread Option4;
	Option4.GetInputData();
	cout << "European bear spread price = " << Option4.PriceByCRR(Model) << endl << endl;
	*/

	Strangle Option5;
	Option5.GetInputData();
	cout << "European strangle option price = " << Option5.PriceByCRR(Model) << endl << endl;
	Butterfly Option6;
	Option6.GetInputData();
	cout << "European butterfly option price = " << Option6.PriceByCRR(Model) << endl << endl;

	int x;
	cin >> x;
}
/*
Output:
Enter S0: 106
Enter U:  0.1525
Enter D:  -0.13138
Enter R:  0.00545

Input data checked
There is no arbitrage

Enter call option data:
Enter steps to expiry N: 8
Enter strike price K:    100

European call option price = 21.7726

Enter put option data:
Enter steps to expiry N: 8
Enter strike price K:    100

European put option price = 11.5176

Enter put option data:
Enter steps to expiry N: 8
Enter strike price K1:    100
Enter strike price K2:    110

European strangle option price = 28.4991

Enter put option data:
Enter steps to expiry N: 8
Enter strike price K1:  100
Enter strike price K2:  110

European butterfly option price = 0.921831


*/

