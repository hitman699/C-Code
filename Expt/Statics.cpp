#include<bits/stdc++.h>
#define pb push_back
using namespace std;
void addList();
class Human
{
    public:
    static int x;
    static vector<int>list;
    Human()
    {
        addList();
        //this->list.pb(10);
    }
    static void hello()
    {
        cout<<"Hello World"<<endl;
        cout<<Human::x<<endl;
        
    }
};
vector<int>Human::list;
int Human::x=100;
int32_t main()
{
    Human a;
    a.hello();
}
void addList()
{
    Human::list.pb(10);
}