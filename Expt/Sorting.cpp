#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    vector<string>a{"Aman","Hello","ZZZ","BBB","B"}; //LEXICOGRAPHICAL SORTING
    sort(a.begin(),a.end());
    for(auto i=a.begin();i!=a.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}