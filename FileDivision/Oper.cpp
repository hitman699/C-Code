#include<bits/stdc++.h>
#define pb push_back
#include"Oper.h"
using namespace std;

    vector<int>Human::myVector;  //DONT DECLARE STATIC IN .h files
    int Human::count=0;          //DONT DECLARE STATIC IN .h files

    
    Human::Human(int id,string name)
    {
        Human::count++;
        this->id=id;
        this->name=name;
        Human::myVector.pb(this->id);
    }
    
ostream & operator << (ostream & out,Human &h)
{
    out<<h.id<<"----"<<h.name<<endl;
    return out;
}
