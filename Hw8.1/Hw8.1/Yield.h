#ifndef Yield_h
#define Yield_h
#include <cmath>
#include <iostream>
using namespace std;

class BondPrice
{
private:
	double Coupon;
	double FaceValue;
	int T;
	double Price;
public:
	void getInputData() {
		cout << "double F = "; cin >> FaceValue;
		cout << "int T = "; cin >> T;
		cout << "double C = "; cin >> Coupon;
		cout << "double P = "; cin >> Price;
	}
	double Value(double y) {
		double val = FaceValue * exp(-y*T);
		for (int i = 1; i <= T; i++)
		{
			val += Coupon*exp(-y*i);
		}
		return val;
	}
	double Deriv(double y) {
		double der = -T*exp(-y*T)*FaceValue;
		for (int i = 1; i <= T; i++) {
			der += (-i)*Coupon*exp(-y*i);
		}
		return der;
	}
	double getPrice() { return Price; }
};



#endif // !1