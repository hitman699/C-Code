#include <bits/stdc++.h>
using namespace std; 	
class coefficients
{
private:
	vector<double> coefficients_array;
public:
	coefficients();
	~coefficients();
	void add_coefficients(string s);
	vector<double> get_coefficients();
};