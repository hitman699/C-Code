#include<bits/stdc++.h>
using namespace std;
class Person
{
    public:
    string name;
    int age;
    Person(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
    friend class B;
};
class B
{
    private:
    string name;
    int age;
    public:
    B(string iname,int iage)
    {
        this->name=iname;
        this->age=iage;
        Person a1(iname,iage);
    }
    void printPersonDetails(Person p)
    {
        cout<<p.name<<"  "<<p.age<<endl;
    }

};
int32_t main()
{
    Person a1("HEllO",100);
    B b1("Aman",18);
    b1.printPersonDetails(a1);
}