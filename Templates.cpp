#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
template<typename T,typename U>
class calculator
{
    private:
    T x;
    U y;
    public:
    calculator(T x,U y)
    {
        this->x=x;
        this->y=y;
    }
    T add(T x,T y)
    {
        return x+y;
    }
    static U multiply(U x,U y)
    {
        return x*y;
    }
    static U mixAdd(T x,U y)
    {
        return x+y;
    }
    U normalNon(U a)
    {
        return a;
    }
};

template<typename X>
X tempFunc(X a,X b)
{
    return a+b;
}


int32_t main()
{
    calculator<double,double> c1(10,20.2);
    double answerD=c1.add(10.2,40.2);  //50.4
    int answerI=c1.add(10,10.2);   //20
    cout<<answerD<<"    "<<answerI<<endl;
    calculator<double,double> c2(10.3,20.4);
    double ans=calculator<int,double>::multiply(10.90,20.99);
    cout<<ans<<endl;
    cout<<"-----"<<endl;
    double ansNON=c1.normalNon(10.984);
    cout<<ansNON<<endl;
    cout<<"-------"<<endl;
    double valueFunction=tempFunc<double>(10.9,98.2);
    cout<<valueFunction<<endl;
}