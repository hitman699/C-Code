#include<bits/stdc++.h>
using namespace std;
class Person
{
    protected:
    string name;
    int age;
    void printDetails()
    {
        cout<<this->name<<"    "<<this->age<<endl;
    }
    public:
    int a;
    Person(string name,int age)
    {
        this->name=name;
        this->age=age;
        this->a=100;
    }
};
class Student : public Person
{
    public:
    int id;
    Student(string name,int age,int id) : Person(name,age)
    {
        this->id=id;
    }
    void print()
    {
        this->printDetails();
    }
    
};
int32_t main()
{
    Student s1("Aman",19,1);
    Student s2("Jimmy",3,2);
    //cout<<s1.name<<"  "<<s1.age<<" "<<s1.id<<endl;
    s1.print();
    cout<<s1.a<<endl;
}