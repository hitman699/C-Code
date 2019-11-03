#include<bits/stdc++.h>
using namespace std;
class Person //Abstract Class
{
    public:
    virtual void introduce()=0;//PURE VIRTUAL FUNCTION
    virtual void show()=0;//PURE VIRTUAL FUNCTION
    virtual void originalIdentity()
    {
        cout<<"PERSON"<<endl;
    }
};
class Student : public Person
{
    public:
    void introduce()
    {
        cout<<"I am in student class"<<endl;
    }
    void show()
    {
        cout<<"I am a student"<<endl;
    }
   /* void originalIdentity()
    {
        cout<<"STUDENT"<<endl;
    }*/
};
class Farmer : public Person
{
    public:
    void introduce()
    {
        cout<<"I am in Farmer class"<<endl;
    }
    void show()
    {
        cout<<"I am a FARMER"<<endl;
    }
    void originalIdentity()
    {
        cout<<"FARMER"<<endl;
    }
};
int32_t main()
{
    Person *p1;
    Student s1;
    Farmer f1;
    p1=&s1;
    p1->introduce();  //STUDENT CLASS
    p1->show();
    p1->originalIdentity();
   // Person p1;   Abstract Class Objects can't be declared
   //Abstract Class Has one or more PURE VIRTUAL FUNCTIONS
}