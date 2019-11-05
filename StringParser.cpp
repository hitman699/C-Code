#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int32_t main()
{
    string x;
    //cin>>x;
    getline(cin,x);
    stringstream check(x);
    string store;
    vector<string>a;
    while(getline(check,store,'-'))
    {
        a.pb(store);
    }
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    string finals;
    for(int i=0;i<a.size();i++)
    {
        finals+=a[i];
    }
    cout<<finals<<endl;
    cout<<endl;
}