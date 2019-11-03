#include<bits/stdc++.h>
using namespace std;
class Person
{
    protected:
        string name;
        void setName(string name)
        {
            this->name=name;
        }
    
};
class Student: private Person
{
    //protected:
    public:
        //add using to give no warning
        using Person :: name;////WORKING
        //Person :: this->name is wrong
        using Person :: setName;
        void display()
        {
            cout<<this->name<<endl;
        }
        //setName included here
        void setStudentName(string i)
        {
            this->setName(i);   //setName is accessible FROM HERE
        }
};
class GStudent : /*private*/public Student
{
    public:
    void setGSName(string s)
    {
        this->setStudentName(s);  //setName is not accessible FROM HERE
    }
    void printName()
    {
        this->display();
    }
};
int32_t main()
{
    GStudent g1;
    g1.setGSName("Aman");
    g1.printName();
    g1.display();
    cout<<g1.name<<endl;
    g1.setName("Amankumar");
    cout<<g1.name<<endl;
}