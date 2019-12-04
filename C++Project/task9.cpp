
#include"task9.h"
#include <bits/stdc++.h>
using namespace std;
Task9::Task9(string equation):Equation(equation)
{
    LHSX = 1, RHSX = 0, LHSNum = 0; RHSNum = 0;
	setEqn(equation.substr(1,equation.size()-2));

}
void Task9::setEqn(string equation)
{
			int equalsTo = equation.find("=");
        		char signNum, signChar;
      	int magNum, magChar;
	string LHS = equation.substr(1, equalsTo-2);
	string RHS = equation.substr(equalsTo+1, equation.size()-equalsTo-1);
	stringstream sl(LHS), sr(RHS);
	if((LHS[LHS.size()-1] >= 'a') && (LHS[LHS.size()-1] <= 'z'))
	{
		if(LHS[0] == '-')
		{
			sl >> signNum;
		}
		else
		{
			signNum = '+';
		}
		sl >> magNum >> signChar;
		if((LHS[LHS.size()-2] == '+') || (LHS[LHS.size()-2] == '-'))
		{
			magChar = 1;
		}
		else
		{
			sl >> magChar;
		}
	}
			else
                        {
                                if(LHS[0] == '-')
                                {
                                        sl >> signChar;
                                }
                                else
                                {
                                        signChar = '+';
                                }
                                if((LHS.find("x") == 0) || (LHS[LHS.find("x")-1] == '+') || (LHS[LHS.find("x")-1] == '-'))
                                {
                                        magChar = 1;
                                }
                                else
                                {
                                        sl >> magChar;
                                }
                                sl >> ch >> signNum >> magNum;
                        }
                        LHSX = magChar * (signChar == '+' ? 1 : -1);
                        LHSNum = magNum * (signNum == '+' ? 1 : -1);
                        if((RHS[RHS.size()-1] >= 'a') && (RHS[RHS.size()-1] <= 'z'))
                        {
                                if(RHS[0] == '-')
                                {
                                        sr >> signNum;
                                }
                                else
                                {
                                        signNum = '+';
                                }
                                sr >> magNum >> signChar;
                                if((RHS[RHS.size()-2] == '+') || (RHS[RHS.size()-2] == '-'))
                                {
                                        magChar = 1;
                                }
                                else
                                {
                                        sr >> magChar;
                                }
                        }
			else
                        {
                                if(RHS[0] == '-')
                                {
                                        sr >> signChar;
                                }
                                else
                                {
                                        signChar = '+';
                                }
                                if((RHS.find("x") == 0) || (RHS[RHS.find("x")-1] == '+') || (RHS[RHS.find("x")-1] == '-'))
                                {
                                        magChar = 1;
                                }
                                else
                                {
                                        sr >> magChar;
                                }
                                sr >> ch >> signNum >> magNum;
                        }
                        RHSX = magChar * (signChar == '+' ? 1 : -1);
                        RHSNum = magNum * (signNum == '+' ? 1 : -1);
}
double Task9::getPS()
{
			if(((LHSX - RHSX) == 0) && ((RHSNum - LHSNum) != 0)) 
			{
				cout << "Solution Not Possible" << endl;
				return 0.0;
			}
			if(((LHSX - RHSX) == 0) && ((RHSNum - LHSNum) == 0)) 
			{
				cout << "Infinite Solution" << endl;
				return 0.0;
			}
			return ((RHSNum - LHSNum) / (LHSX - RHSX));
}
double Task9::getNS()
{
			if(((-LHSX - RHSX) == 0) && ((RHSNum + LHSNum) != 0)) 
			{
				cout << "Solution Not Possible" << endl;
				return 0.0;
			}
			if(((-LHSX - RHSX) == 0) && ((RHSNum + LHSNum) == 0)) 
			{
				cout << "Infinite Solution" << endl;
				return 0.0;
			}
			return ((RHSNum + LHSNum) / (-LHSX - RHSX));
}
void Task9::solve(){
	}
void Task9::setCoefficients(){}
void Task9::print(){
    cout<<*this;
}

ostream& operator<<(ostream& os, Task9& eq)
{
    os<<"x="<<fixed<<setprecision(4)<<eq.getPS()<<";x="<<eq.getNS()<<endl;
    return os;
}
