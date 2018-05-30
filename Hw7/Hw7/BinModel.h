#ifndef BinModel02_h
#define BinModel02_h

class BinModel
{
private:
	double U;
	double D;
	double R;

	double S0;
	double r;
	double sigma;
	double T;
	double K;
	int N;

public:
	//computing risk-neutral probability
	double RiskNeutProb();
	//computing the stock price at node n,i
	double S(int n, int i);
	//inputting, displaying and checking model data
	int GetInputData();
	double GetR();
	double GetU();
	double GetD();
	double GetN() { return N; }
	double GetK() { return K; }
};
#endif // !BinModel01_h
