#include<bits/stdc++.h>
using namespace std;
class Person
{
    protected:
    string name;
    int age;
    public:
    Person(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
    void getDetails()
    {
        cout<<"In person: "<<this->name<<"  "<<this->age<<endl;
    }
};
class Student: protected Person
{
    public:
    int id;
    Student(string name,int age,int id): Person(name,age)
    {
        this->id=id;
    }
    void printDetails()
    {
        this->getDetails();
    }
};
int32_t main()
{
    Student s1("Aman",18,1);
    Student s2("Jimmy",3,2);
    s1.printDetails();
}