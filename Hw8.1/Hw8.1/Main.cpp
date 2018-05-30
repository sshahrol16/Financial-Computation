#include "Solver03.h"
#include "Yield.h"
#include <iostream>
#include <iomanip>
using namespace std;
class F1
{
public:
	double Value(double x) { return x*x - 2; }
	double Deriv(double x) { return 2 * x; }
} MyF1;
class F2
{
private:
	double a; //parameter
public:
	F2(double a_) { a = a_; }
	double Value(double x) { return x*x - a; }
	double Deriv(double x) { return 2 * x; }
} MyF2(3.0);

int main()
{
	cout << "Assignment 1: Pass by Reference" << endl;
	cout << setiosflags(ios::fixed) << setprecision(4);
	double Acc = 0.001;
	double LEnd = 0.0, REnd = 2.0;
	double Tgt = 0.0;
	double Guess = 1.0;
	cout << "Root of F1 by bisect: " << SolveByBisect(MyF1, Tgt, LEnd, REnd, Acc) << endl;
	cout << "Root of F2 by bisect: " << SolveByBisect(MyF2, Tgt, LEnd, REnd, Acc) << endl;

	cout << "Root of F1 by Newton-Raphson: " << SolveByNR(MyF1,Tgt,Guess,Acc)
		<< endl;
	cout << "Root of F2 by Newton-Raphson: " << SolveByNR(MyF2, Tgt, Guess, Acc)
		<< endl << endl;

	cout << "Assignment 2: Calculate Yield" << endl;
	Acc = 0.0001;
	LEnd = 0.0;
	REnd = 1.0;
	Guess = 0.2;

	BondPrice P1;
	P1.getInputData();
	Tgt = P1.getPrice();
	
	cout << "Yield by Bisection Method: " << SolveByBisect(P1, Tgt, LEnd, REnd, Acc) << endl;
	cout << "Yield by Newton-Raphson Method: " << SolveByNR(P1, Tgt, Guess, Acc) << endl;
	int x;
	cin >> x;
	return 0;
}
/*
Output:

Assignment 1: Pass by Reference
Root of F1 by bisect: 1.4150
Root of F2 by bisect: 1.7314
Root of F1 by Newton-Raphson: 1.4142
Root of F2 by Newton-Raphson: 1.7321

Assignment 2: Calculate Yield
double F = 100
int T = 3
double C = 1.2
double P = 98.56
Yield by Bisection Method: 0.0168
Yield by Newton-Raphson Method: 0.0168


*/