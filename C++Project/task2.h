#include"Equation.h"
using namespace std;
class task2:public Equation
{
    private:
    vector<string> eqs;
    string eq1;
    string eq2;
    float a1;
    float a2;
    float b1;
    float b2;
    float c1;
    float c2;
    public:
    float x;//
    float y;//
    task2(string s);
    void solve();
	void print();
   // void set_equation(string );
    void divide1(string eq,float &b,int i,int j); //declared here;
    void divide(string eq,float &a,float &b,float &c,int i); //declared here;
    void parsing(string eq,float &a,float &b,float &c);//declared here;
    void setCoefficients();
    friend ostream& operator<<(ostream& os, const task2 &eq);//declared here;
};
