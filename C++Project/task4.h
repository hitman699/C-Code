#ifndef QUADRATIC_H
#define QUADRATIC_H
#include<bits/stdc++.h>
#include"Equation.h"
using namespace std;

class Quadratic : public Equation
{
    string quadratic, linear, constant;
    float a, b, c,x1,x2;

    public:
        Quadratic(string s);
        void setCoefficients();
        void solve();
        void print();
        friend ostream& operator<<(ostream& os, const Quadratic& eq);
};

#endif