#include<bits/stdc++.h>
using namespace std;
class Marks
{
	private:
		int mark1;
		int mark2;
	public:
		Marks()
		{
		}
		Marks(int m1,int m2)
		{
			this->mark1=m1;
			this->mark2=m2;
		}
		Marks operator+(Marks m)  //Overloading PLUS OPERATOR
		{
			Marks temp;
			temp.mark1=this->mark1+m.mark1;
			temp.mark2=this->mark2+m.mark2;
			return temp;
		}
		void display()
		{
			cout<<this->mark1<<"  "<<this->mark2<<endl;
		}
};
class add
{
	public:
		int m1;
		int m2;
		add(int m,int n)
		{
			this->m1=m;
			this->m2=n;
		}
		int operator-(add m)
		{
			return (this->m1-m.m1);
		}
};
int32_t main()
{
	Marks m1(10,20);
	Marks m2(20,20);
	Marks m3(10,20);
	Marks m4=m1+m2;  //m1.add(m2)[this-> belongs to m1 and object in bracket is m2];
	m4.display();
	Marks m5=m4+m3+m2+m1;  //Takes two at a time and add;
	m5.display();

	//
	cout<<"-------"<<endl;
	add a(10,20);
	add b(30,50);
	int ans=a-b;
	cout<<ans<<endl;
}
