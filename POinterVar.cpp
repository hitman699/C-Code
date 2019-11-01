#include<bits/stdc++.h>
using namespace std;
class Human
{
	private:
		string *name;
		int *age;
	public:
		
		Human(string iname,int iage)
		{
			this->name=new string;
			this->age=new int;
		//	*name=iname;
			*(this->name)=iname;
			*(this->age)=iage;

		}
		void display()
		{
			cout<<*(this->name)<<"  "<<*(this->age)<<endl;  //Different address printed;
		}
};
int32_t main()
{
	string x="Aman";
	int y=10;
	string *ptrx=&x;
	int *ptry=&y;
	//cout<<ptrx<<"  "<<ptry<<endl;
	//cout<<&x<<"  "<<&y<<endl;
	Human a1(x,y);
	a1.display();
}
