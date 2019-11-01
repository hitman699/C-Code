#include<bits/stdc++.h>
using namespace std;
class Human
{
	private:
		string name;
		int age;
		int height;
	public:
	/*	Human(string name,int age)
		{
			this->name=name;
			this->age=age;
		}*/
		//Cannot be overloaded
		/*
		Human(string name="noname",int age=0)
		{
			this->name=name;
			this->age=age;
		}
		Human(string name="noname",int age)
		{
			this->age=age;
		}*/
		Human()
		{
			this->name="hello";
			this->age=0;
			this->height=0;
		}
		Human(string name,int age,int height=100)
		{
			this->name=name;
			this->age=age;
			this->height=height;
		}
		void printDetails()
		{
			cout<<this->name<<"  "<<this->age<<"  "<<this->height<<endl;
		}
};
int32_t main()
{
	Human a("Aman",10);
	a.printDetails();
}
