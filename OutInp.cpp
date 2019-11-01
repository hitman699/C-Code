#include<bits/stdc++.h>
using namespace std;
class Human
{
	public:
		Human()
		{
		}
	private:
		string name;
		int age;
		/*Human()  //CONSTRUCTOR 1 CALLED
		{
		}*/
		Human(string name,int age)
		{
			this->name=name;
			this->age=age;
		}
		friend istream & operator >> (istream &input,Human &h);
		friend ostream & operator << (ostream &output,Human &h);
};
ostream & operator << (ostream &out,Human &h)
{
	out<<"Hello World"<<endl;
	out<<h.name<<" "<<h.age<<endl;
	return out;
}
istream & operator >>(istream &inp,Human &h)
{
	inp>>h.name>>h.age;
	return inp;
}
int32_t main()
{
	Human a;  //CONSTRUCTOR 1 CALLED
	cin>>a;
	cout<<a;
}
