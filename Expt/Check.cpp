#include<bits/stdc++.h>
using namespace std;
class ShortestRoute
{
    public:
    static vector<int>hello;
};
vector<int>ShortestRoute::hello;
int32_t main()
{
    ShortestRoute::hello.push_back(10);
    ShortestRoute::hello.push_back(20);
    ShortestRoute::hello.push_back(30);
    ShortestRoute::hello.push_back(40);
    for(auto i=ShortestRoute::hello.begin();i!=ShortestRoute::hello.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}