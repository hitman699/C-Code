#ifndef TASK8_LOG
#define TASK8_LOG
#include<bits/stdc++.h>
#include"Equation.h"

using namespace std;
//Format : ln(ax+b) +ln(cx+d) =g
class Task8 : public Equation
{   

    private:  
        string eq;
        double a,b,c,d,g;
        string out;
        int knowequation();
        void setcoeffquad();
        void setcoefflinear();

    public:
        Task8(string s);
        void solve();
        void print();
        void setCoefficients();
        friend ostream & operator<<(ostream &os,Task8 & task);
        ~Task8();
};

#endif

