#include<bits/stdc++.h>
#include"Oper.h"
using namespace std;

int32_t main()
{
    Human h1(1,"Aman");
    cout<<h1<<endl;
    for(int i=0;i<Human::myVector.size();i++)
    {
        cout<<"Here"<<endl;
        cout<<Human::myVector[i]<<endl;
    }
    cout<<"The count is "<<Human::count<<endl;
}