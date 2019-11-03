#include<bits/stdc++.h>
using namespace std;
class A
{
    private:
    string name;
    int age;
    A(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
    friend class B;
};
class B
{
    public:
    string name;
    int age;
    B(string name,int age)
    {
        A a1(name,age);
    }
};
int32_t main()
{
    B b1("Aman",18);
    B b2("Jimmy",3);
   // cout<<b1.a1.name<<endl;
   // cout<<a1.name<<endl;
}