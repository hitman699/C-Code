#include<bits/stdc++.h>
#define pb push_back
using namespace std;
class Human
{
    public:
    int id;string name;
    vector<int>myVec;
    Human(int id,string name)
    {
        this->id=id;
        this->name=name;
        this->myVec.pb(id);
    }
    friend ostream & operator << (ostream &out,Human &h);
    friend istream & operator >> (istream &in ,Human &h);
};
ostream & operator << (ostream & out,Human &h)
{
    out<<h.id<<"----"<<h.name<<endl;
    return out;
}

int32_t main()
{
    Human h1(1,"Aman");
    cout<<h1<<endl;
    for(int i=0;i<h1.myVec.size();i++)
    {
        cout<<h1.myVec[i]<<endl;
    }
}