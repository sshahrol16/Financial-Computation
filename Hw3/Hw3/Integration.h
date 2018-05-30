#ifndef Integration_h
#define Integration_h

class DefInt
{
private:
	double a, b;
	double(*f)(double x);
public:
	DefInt(double start, double end, double(*function)(double x));
	double ByTrapezoid(int N);
	double BySimpsons(int N);

};

double f1(double x);

#endif