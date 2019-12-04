#include<bits/stdc++.h>
using namespace std;
class Vehicle
{
    public:
    void printName()
    {
        cout<<"In vehicle class"<<endl;
    }
    virtual void typeVehicle()=0;
};
class Lvehicle : public Vehicle
{
    public:
    //vector<Lvehicle>listOfland;
   
    void printName()
    {
        cout<<"In Land vehicle"<<endl;
    }
    void typeVehicle()
    {
        cout<<"I am Lvehicle"<<endl;
    }
};
class Wvehicle : public Vehicle
{
    public:
    void printName()
    {
        cout<<"In water vehicle"<<endl;
    }
    void typeVehicle()
    {
        cout<<"I am Wvehicle"<<endl;
    }
};

void findType(Vehicle &v)  //VEHICLE V CANT BE WRITTEN AS IT IS ABSTRACT CLASS
{
    v.typeVehicle();
}
int32_t main()
{
    Lvehicle l1;
    Wvehicle w1;
    l1.printName();
    w1.printName();

    Vehicle &v1=l1;
    v1.printName();  //WILL CALL VEHICLE CLASS

    Vehicle *v2=new Lvehicle();
    v2->printName();


    cout<<"------------"<<endl;
    l1.typeVehicle();
    w1.typeVehicle();
    Vehicle &v=l1;

    cout<<"--------"<<endl;
    Vehicle &vw=w1;

    //EXAMPLES OF POLYMORPHISM
    vw.printName();    //WILL PRINT VEHICLE CLASS  //NOT A VIRTUAL FUNCTION
    findType(vw);      // WILL CALL WVEHICLE  //BECAUSE IT IS A VIRTUAL FUNC
    v.typeVehicle();   //WILL CALL LVEHICLE   //BECAUSE IT IS A VIRTUAL FUNC

    Lvehicle a1;
    Lvehicle a2;
    Lvehicle a3;
    Lvehicle a4;


}

