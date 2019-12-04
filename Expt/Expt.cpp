#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    int date;
    cin>>date;
    cout<<"The date is "<<endl;
    int year=date%10000;
    date=date/10000;
    int month=date%100;
    date=date/100;
    int day=date%100;
    cout<<day<<"---"<<month<<"---"<<year<<endl;
}