#include "BinModel.h"
#include "Options.h"
#include <iostream>
using namespace std;

int main()
{
	BinModel Model;
	Model.GetInputData();

	Call Option1;
	Put Option2;
	cout << "U = " << Model.GetU() << endl;
	cout << "D = " << Model.GetD() << endl;
	cout << "R = " << Model.GetR() << endl;
	cout << "American call option price = " << Option1.PriceByCRR(Model) << endl;

	cout << "American put option price = " << Option2.PriceByCRR(Model) << endl;
	int x;
	cin >> x;
}

/*
Output

Enter S0: 106
Enter r:  0.058
Enter sigma:  0.46
Enter T:  0.75
Enter K:  100
Enter N:  8

U = 0.146099
D = -0.13526
R = 0.00545231
American call option price = 21.334
American put option price = 11.0772

*/
