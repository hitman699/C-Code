#include<bits/stdc++.h>
#define pb push_back
using namespace std;
class AstroObservation
{
    public:
    static vector<AstroObservation>list;
    string name;
    AstroObservation(string name)
    {
        this->name=name;
        AstroObservation::list.pb(*this);
    }

};
vector<AstroObservation>AstroObservation::list; //INITIALIZE MEMORY 
int32_t main()
{
    AstroObservation a("X");
    AstroObservation b("Y");
    AstroObservation c("Z");
    for(auto i=AstroObservation::list.begin();i!=AstroObservation::list.end();i++)
    {
        cout<<i->name<<" ";
    }
    cout<<endl;
}