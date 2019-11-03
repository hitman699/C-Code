#include<bits/stdc++.h>
using namespace std;
class Person
{
    public:
    void introduce()
    {
        cout<<"Person Class"<<endl;
    }
};
class Student : public Person
{
    public:
    void introduce()
    {
        cout<<"Student Class"<<endl;
    }
};
int32_t main()
{
    Student s;
    s.introduce();
    s.Person::introduce();
}