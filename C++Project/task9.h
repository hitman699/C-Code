#ifndef Task_9_h_
#define Task_9_h_

#include <bits/stdc++.h>
#include"Equation.h"
using namespace std;

class Task9:public Equation
{
	private :
                char ch;
                double LHSX, RHSX, LHSNum, RHSNum;
        public : 
                Task9(string equation);
		void setEqn(string equation);
		double getPS();
		double getNS();
		void print();
		void solve();
		void setCoefficients();
		friend ostream& operator<<(ostream& os,Task9& eq);
};

#endif
