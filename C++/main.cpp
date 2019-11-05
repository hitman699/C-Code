#include"Hello.h"
#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    int n,m;
    cin>>n>>m;
    Store s1(n,m);  //n=Bakeries m=Dairies
    while(1)
    {
        string name;
        int capacity;
        cin>>name;
        if(name=="End")
            break;
        else
        {
            cin>>capacity;
            Product p1(name,capacity);
            s1.addProduct(p1);
        }
    }
    cout<<s1.bakerySize<<"  "<<s1.dairySize<<endl;
    s1.compute();
    s1.printBakery();
    s1.printDairy();
}