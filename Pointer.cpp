#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
	int number=10;
	int *a=&number;
	cout<<a<<"  "<<&number<<endl;
	int **ptr=&a;
	cout<<*ptr<<endl;
	cout<<ptr<<"  "<<&a<<" is the address of pointer"<<endl;

	int *b=new int();
	*b=10;
	cout<<*b<<endl;

	//Create 2d array
}
