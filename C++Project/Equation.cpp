#include<bits/stdc++.h>
#include "Equation.h"
using namespace std;

Equation::Equation(string s) : _equation(s){}
string Equation::getEquation(){
    return _equation;
}
Equation::~Equation(){}