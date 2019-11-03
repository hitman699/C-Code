#include<bits/stdc++.h>
using namespace std;
class Person
{
    public:
    string name;
    int age;
    Person(string iname,int iage)
    {
        this->name=iname;
        this->age=iage;
    }
    void setAge(int age)
    {
        this->age=age;
    }
    void setName(string name)
    {
        this->printHello();
        this->name=name;
    }
    private:
    void printHello()
    {
        cout<<"HelloWorld"<<endl;
    }
};
class Student: public Person
{
    public:
    int id;
    Student(string name,int age,int id): Person(name,age)
    {
        this->id=id;
    }
    void printDetails()
    {
        cout<<this->name<<"  "<<this->age<<"  "<<this->id<<endl;
    }
};
int32_t main()
{
    Student s1("Aman",18,1);
    Student s2("Jimmy",3,2);
    s1.setName("Aman Kumar");
    s1.printDetails();
    s2.printDetails();
    
}