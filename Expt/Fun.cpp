#include<bits/stdc++.h>
using namespace std;
class Vehicle
{
    public:
    int id;
    Vehicle(int id)
    {
        this->id=id;
    }
    virtual void printHello()
    {
        cout<<"Hello from Vehicle class"<<endl;
    }
    virtual void printX()=0;
};
class lVehicle : public Vehicle
{
    public:
    int id;
    string name;
    lVehicle(int id,string name): Vehicle(id)
    {
        this->id=id;
        this->name=name;
    }
    void printX()
    {
        cout<<"From LAND CLASS"<<endl;
    }
};
class wVehicle: public Vehicle
{
    public:
    int id;
    string name;
    wVehicle(int id,string name): Vehicle(id)
    {
        this->id=id;
        this->name=name;
    }
    void printHello()
    {
        cout<<"OVERRIDE BY WATER"<<endl;
    }
    void printX()
    {
        cout<<"From WATER CLASS"<<endl;
    }
};
int32_t main()
{
    //Vehicle v1(10);  CANT BE DONE
    Vehicle *v=new lVehicle(10,"BAJAJ");
    v->printX();      //FROM lVEHICLE CLASS
    v->printHello();  //FROM VEHICLE CLASS

    cout<<"-----"<<endl;

    Vehicle *v1=new wVehicle(20,"SHIP");
    v1->printHello();    //BOTH ARE FROM wVEHICLE CLASS
    v1->printX();        //
}