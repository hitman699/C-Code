#include<bits/stdc++.h>
using namespace std;
class Human
{
	public:
		string name;
		int age;
		Human(string name,int age)
		{
			this->name=name;
			this->age=age;
		}
		~Human()
		{
			cout<<"Destructor called for "<<this->name<<endl;
		}
		void print()
		{
			cout<<this->name<<"  "<<this->age<<endl;
		}
};
int32_t main()
{
	Human a1("Aman",18);  //Destructor called
	a1.print();

	Human *b1=new Human("Bipul",20);
	b1->print();
	
	delete b1;
	//Destructor for a1 called here;(IMP)
}
