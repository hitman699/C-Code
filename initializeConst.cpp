#include<bits/stdc++.h>
using namespace std;

class Human
{
	public:
		string name;
		const int age;
		Human(string name,int val) : age(val)
		{
			this->name=name;
		}
		void printDetails()
		{
			cout<<this->name<<" "<<this->age<<endl;
		}
};
int32_t main()
{
	Human a("Aman",100);
	Human b("Jimmy",500);
	a.printDetails();
	b.printDetails();
}
