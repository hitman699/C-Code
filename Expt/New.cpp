#include<bits/stdc++.h>
using namespace std;
class Position
{
    public:
    int id;
    Position(int id)
    {
        this->id=id;
    }
};
bool comp(Position* a,Position *b)
{
    if(a->id < b->id)
    {
        return 1;
    }
    else
    {
        return 0;
    }  
}
class Vehicle
{
    public:
    vector<Position*>list;
    Vehicle(vector<Position*>l)
    {
        this->list=l;
    }
    void sortData()
    {
        sort(this->list.begin(),this->list.end(),comp);
    }
    void print()
    {
        for(int i=0;i<this->list.size();i++)
        {
            cout<<this->list[i]->id<<endl;
        }
    }
};

int32_t main()
{
    Position *p1=new Position(40);
    Position *p2=new Position(1020);
    Position *p3=new Position(30);
    Position *p4=new Position(20);
    vector<Position*>list;
    list.push_back(p1);
    list.push_back(p2);
    list.push_back(p3);
    list.push_back(p4);
    Vehicle v1(list);
    v1.sortData();
    v1.print();
}