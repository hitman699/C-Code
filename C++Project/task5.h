#ifndef X_H
#define X_H
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#include"Equation.h"
using namespace std;
class myTask : public Equation
{
    public:
    vector<string>equationList;
    vector<int>a;vector<int>b;vector<int>c;vector<int>d;
    float answerX,answerY,answerZ;

    myTask(string x);//UNPARSED STRING 
    ~myTask();
    int solveDeterminant(vector<vector<int>>matrix); 
    void solve();  
    void setCoefficients();  
    void printVariables();
    void print();
    friend ostream& operator<<(ostream& os,myTask& t);

};
#endif  

