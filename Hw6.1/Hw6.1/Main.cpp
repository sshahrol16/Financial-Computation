#include "BinLattice02.h"
#include "BinModel02.h"
#include "Options09.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	BinModel Model;
	if (Model.GetInputData() == 1) return 1;

	ofstream fout;
	fout.open("Results.txt");

	Call Option1;
	Option1.GetInputData();
	BinLattice<double> PriceTree;
	BinLattice<double> XTree;
	BinLattice<double> YTree;

	fout << "S0 = " << Model.GetS0() << endl
		<< "U = " << Model.GetU() << endl
		<< "D = " << Model.GetD() << endl
		<< "R = " << Model.GetR() << endl;

	fout << "N = " << Option1.GetN() << endl
		<< "K = " << Option1.GetK() << endl;

	fout << "European call prices by PriceByCRR:"
		<< Option1.PriceByCRR(Model) << endl << endl;

	fout << "European call prices by PriceByCRRHW6:"
		<< Option1.PriceByCRRHw6(Model, PriceTree, XTree, YTree)
		<< endl << endl;
	fout << "Option Price in replicating strategy:" << endl << endl;
	PriceTree.Display(fout);
	fout << "Stock positions in replicating strategy:" << endl << endl;
		XTree.Display(fout);
	fout << "Money market account positions in replicating strategy:" << endl << endl;
		YTree.Display(fout);

	Put Option2;
	Option2.GetInputData();
	BinLattice<double> PriceTree2;
	BinLattice<double> XTree2;
	BinLattice<double> YTree2;

	fout << "European put prices by PriceByCRR:"
		<< Option2.PriceByCRR(Model) << endl << endl;

	fout << "European put prices by PriceByCRRHW6:"
		<< Option2.PriceByCRRHw6(Model, PriceTree2, XTree2, YTree2)
		<< endl << endl;
	fout << "Option Price in replicating strategy:" << endl << endl;
	PriceTree2.Display(fout);
	fout << "Stock positions in replicating strategy:" << endl << endl;
	XTree2.Display(fout);
	fout << "Money market account positions in replicating strategy:" << endl << endl;
	YTree2.Display(fout);
	int stop;
	cin >> stop;
}

/*
Results:

S0 = 106
U = 0.15125
D = -0.13138
R = 0.00545
N = 8
K = 100
European call prices by PriceByCRR:21.6811

European call prices by PriceByCRRHW6:21.6811

Option Price in replicating strategy:

21.681
12.057 32.180
5.574 19.101 46.479
1.875  9.578 29.464 65.132
0.322  3.551 16.107 44.028 88.353
0.000  0.670  6.661 26.354 63.356115.982
0.000  0.000  1.391 12.352 41.571 87.283147.869
0.000  0.000  0.000  2.889 22.574 62.281114.907184.657
0.000  0.000  0.000  0.000  5.999 40.489 86.202146.788227.087

Stock positions in replicating strategy:

0.672
0.520  0.794
0.341  0.664  0.898
0.164  0.483  0.810  0.970
0.039  0.265  0.657  0.932  1.000
0.000  0.071  0.421  0.847  1.000  1.000
0.000  0.000  0.128  0.657  1.000  1.000  1.000
0.000  0.000  0.000  0.231  1.000  1.000  1.000  1.000
0.000  0.000  0.000  0.000  0.000  0.000  0.000  0.000  0.000

Money market account positions in replicating strategy:

-49.518
-35.805-64.687
-21.679-51.260-79.722
-9.548-34.849-69.325-91.698
-2.047-17.648-53.570-86.893-97.849
0.000 -4.252-32.120-77.029-98.383-98.383
0.000  0.000 -8.830-57.299-98.919-98.919-98.919
0.000  0.000  0.000-18.339-99.458-99.458-99.458-99.458
0.000  0.000  0.000  0.000  0.000  0.000  0.000  0.000  0.000

European put prices by PriceByCRR:11.426

European put prices by PriceByCRRHW6:11.426

Option Price in replicating strategy:

11.426
16.250  6.414
22.388  9.893  2.780
29.725 14.823  4.751  0.712
37.829 21.423  7.957  1.388  0.000
45.968 29.583 12.970  2.704  0.000  0.000
53.390 38.576 20.333  5.271  0.000  0.000  0.000
59.911 47.043 29.988 10.273  0.000  0.000  0.000  0.000
65.649 54.471 39.657 20.023  0.000  0.000  0.000  0.000  0.000

Stock positions in replicating strategy:

-0.328
-0.480 -0.206
-0.659 -0.336 -0.102
-0.836 -0.517 -0.190 -0.030
-0.961 -0.735 -0.343 -0.068  0.000
-1.000 -0.929 -0.579 -0.153  0.000  0.000
-1.000 -1.000 -0.872 -0.343  0.000  0.000  0.000
-1.000 -1.000 -1.000 -0.769  0.000  0.000  0.000  0.000
0.000  0.000  0.000  0.000  0.000  0.000  0.000  0.000  0.000

Money market account positions in replicating strategy:

46.227
60.462 31.580
75.113 45.531 17.070
87.771 62.470 27.994  5.621
95.802 80.202 44.280 10.956  0.000
98.383 94.131 66.262 21.354  0.000  0.000
98.919 98.919 90.089 41.620  0.000  0.000  0.000
99.458 99.458 99.458 81.119  0.000  0.000  0.000  0.000
0.000  0.000  0.000  0.000  0.000  0.000  0.000  0.000  0.000



*/

