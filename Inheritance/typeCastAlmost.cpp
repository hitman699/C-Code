#include<bits/stdc++.h>
using namespace std;
class Person
{
    public:
    virtual void intro()
    {
        cout<<"Person"<<endl;
    }
};
class Student : public Person
{
    public:
    void intro()
    {
        cout<<"Student"<<endl;
    }
};
void name(Person *p1) //Can be done only using pointers
{
    p1->intro();
}
int32_t main()
{
    Student s1;
    s1.intro();
    name(&s1);
    


}