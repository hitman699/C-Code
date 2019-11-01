#include<bits/stdc++.h>
using namespace std;
class HumanBeing
{
	public:
		static string name;
		void printName()
		{
			cout<<this->name<<endl;
		}
		void display(string name)
		{
			this->showMessage();
			cout<<"Hello World"<<" "<<name<<endl;
		}
		int useScope();
	private:
		static int vfx;
		void showMessage()
		{
			cout<<this->vfx<<" private variable"<<endl;
			cout<<"Private Message"<<endl;
		}
};
int HumanBeing::vfx=100;
string HumanBeing::name="noname";
int HumanBeing::useScope()
{
	cout<<"Hello Using Scopex ";
	cout<<name<<endl;
	this->display("sjdfo");
	this->showMessage();
}
int32_t main()
{
	HumanBeing Aman;
//	Aman.display("Aman");
	Aman.name="Aman";
	Aman.printName();
	Aman.useScope();
	//Aman.showMessage();   Cant be used;
	//
	HumanBeing *a1=new HumanBeing();
	a1->name="Bipul";
	a1->printName();

	HumanBeing *a2;
	a2->printName();
	cout<<Aman.name<<endl;


}
