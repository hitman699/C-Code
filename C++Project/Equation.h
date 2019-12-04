#ifndef _EQUATION_
#define _EQUATION_
#include<bits/stdc++.h>
using namespace std;
class Equation
{
    private:
        string _equation;
    protected:
        string getEquation();
    public:
        Equation(string s);
        virtual void solve() = 0;
        virtual void print() = 0;
        virtual void setCoefficients() = 0;
        ~Equation();
};

#endif