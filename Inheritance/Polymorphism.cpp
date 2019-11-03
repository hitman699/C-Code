#include<bits/stdc++.h>
using namespace std;
class Person
{
    public:
    virtual void intro()
    {
        cout<<"Called from Person"<<endl;
    }
};
class Student : public Person
{
    public:
    void intro()
    {
        cout<<"Called from Student"<<endl;
    }
};
class Farmer : public Person
{
    public:
    void intro()
    {
        cout<<"Called From Farmer"<<endl;
    }
};
void name(Person &p)  //If i put Person P(Person class Intro is called);
{
    p.intro();
}
int32_t main()
{
    Farmer f1;
    Student s1;
    name(f1);
    name(s1);
}