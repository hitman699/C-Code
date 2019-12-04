

#include"Equation.h"
class Exponential:public Equation
{
private:
	vector<double> coefficients_array;
	double x;
	string lhs,rhs,output;
	int flag = 0;
public:
	Exponential(string s);
	~Exponential();
	void solve();
	void setCoefficients();
	void print();
	double gx();
	friend ostream& operator<<(ostream& os,Exponential& e);
};