#include<bits/stdc++.h>
using namespace std;
class Number
{
	public:
		static const int a=1;
		static int b;
		void printNumber()
		{
			cout<<this->b<<endl;
			cout<<this->a<<endl;
		}
};
//int Number::a=1000;  //Cant be done
int Number::b=100;  //Can only be done for static data
int32_t main()
{
	Number x;
	Number y;
	//x.a=1000;  //Can't do as const is present(const==final)in java
	x.printNumber();
	y.printNumber();
}
