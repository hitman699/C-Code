#include<bits/stdc++.h>
using namespace std;
class Person
{
    private:
    string name;
    int age;
    public:
    Person(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
    friend void display(Person p1);
};
void display(Person p1)
{
    cout<<p1.name<<" "<<p1.age<<endl;
}
int32_t main()
{
    Person a("Aman",10);
    Person b("Jimmy",20);
    display(a);
    display(b);
}