#include "Integration.h"
#include <cmath>
#include <iostream>

DefInt::DefInt(double start, double end, double(*function)(double x))
{
	a = start;
	b = end;
	f = function;
}

double DefInt::ByTrapezoid(int N)
{
	double sum = 0;
	double h = (b - a) / N;
	sum += f(a) + f(b);
	for (int k = 1; k <= N-1; k++)
	{
		sum += 2 * f(a + k*h);
	}
	sum *= ((b - a) / (2 * N));
	return sum;
}

double DefInt::BySimpsons(int N) {
	double sum = 0;
	double h = (b - a) / N;
	sum += f(a) + f(b);
	for (int k = 1; k <= N - 1; k+=2)
	{
		sum += 4 * f(a + k*h);
	}
	for (int k = 2; k <= N - 1; k += 2)
	{
		sum += 2 * f(a + k*h);
	}
	return sum*(h / 3);
}
double f1(double x)
{
	return x*x*x-x*x+1;
}