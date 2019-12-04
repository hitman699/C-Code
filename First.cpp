#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
class Vehicle
{
    public:
    int id;
    string name;
    static int registered;
    static vector<Vehicle*>listOfVehicles;
    Vehicle(){}
    Vehicle(int id,string name)
    {   
        this->id=id;
        this->name=name;
        Vehicle::listOfVehicles.pb(this);
        Vehicle::registered++;
    }
    ~Vehicle()
    {
        cout<<"Vehicle Class"<<endl;
    }
    virtual void printDetails()=0;
    virtual void parentFunction()
    {
        cout<<"I am in parent class"<<endl;
    }
    static void sortData()
    {
        sort(Vehicle::listOfVehicles.begin(),Vehicle::listOfVehicles.end(),
        [](Vehicle *a,Vehicle *b)
        {
            if(a->id < b->id)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            
        });
    }
};
class lVehicle :public Vehicle
{
    public:
    lVehicle(int id,string name):Vehicle(id,name)    
    {

    }
    lVehicle(const lVehicle &l) : Vehicle()
    {
        this->id=l.id;
    }
    ~lVehicle()
    {
        cout<<"Deleted"<<endl;
    }
    void printDetails()
    {
        cout<<"I am in lVehicle"<<endl;
    }
    void checkList(vector<Vehicle*>&list)
    {
        for(int i=0;i<list.size();i++)
        {
            //list[i]->printDetails();
            cout<<list[i]->id<<endl;
        }
    }
};
class wVehicle :public Vehicle
{
    public:
    wVehicle(int id,string name):Vehicle(id,name)
    {

    }
    wVehicle(const wVehicle &w) :Vehicle()
    {
        this->id=w.id;
        this->name=w.name;
    }
    ~wVehicle()
    {
        cout<<"Deleted---"<<endl;
    }
    void printDetails()
    {
        cout<<"I am in wVehicle"<<endl;
    }
};
vector<Vehicle*>Vehicle::listOfVehicles;  //important
int Vehicle::registered=0;
int32_t main()
{
    wVehicle w1(6,"Ship1");
    lVehicle l1(3,"Car1");
    wVehicle w2(10,"Ship2");
    lVehicle l2(100,"Car2");
    wVehicle w3(-1,"Ship2");
    lVehicle l3(9,"Car2");
    Vehicle::listOfVehicles.pb(&w1);
    l3.parentFunction();
    //for(int i=0;i<Vehicle::listOfVehicles.size();i++)
    //{
    //    Vehicle::listOfVehicles[i]->printDetails();
    //}
    l3.checkList(Vehicle::listOfVehicles);
    cout<<"The registered count is "<<Vehicle::registered<<endl;
    Vehicle::sortData();
    l3.checkList(Vehicle::listOfVehicles);

}