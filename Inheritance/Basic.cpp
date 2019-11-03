#include<bits/stdc++.h>
using namespace std;
class Human
{
    public:
    string *name;
    int *age;
    Human(string name,int age)
    {
        this->name=new string;
        this->age=new int;
        *(this->name)=name;
        *(this->age)=age;
    }
    void introduce()
    {
        cout<<"Hello "<<*(this->name)<<"  "<<*(this->age)<<endl;
    }
};
int32_t main()
{
    Human *a1=new Human("Aman",18);
    cout<<*(a1->name)<<"  "<<*(a1->age)<<endl;
    a1->introduce();
}