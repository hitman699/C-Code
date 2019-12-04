#include <bits/stdc++.h>
#include"task8.h"
#include"task5.h"
#include"task2.h"
#include"task7.h"
#include"task9.h"
#include"task4.h"

using namespace std;
Equation* check_equation(string s){
	vector<pair<char,int>> operators;
	
	operators.push_back(make_pair('x',0));
	operators.push_back(make_pair('l',0));
	operators.push_back(make_pair('(',0));
	operators.push_back(make_pair('^',0));
	operators.push_back(make_pair(';',0));
	operators.push_back(make_pair('=',0));
	operators.push_back(make_pair('|',0));
	vector<pair<char,int>>::iterator it;
	for(int i = 0;i<s.size();i++){
		for(pair<char,int> &it:operators){
			if(s[i] == it.first){
				it.second+=1;
			}
		}
	}
	for (const pair<char,int> &it:operators)
	{
		try{
			if((it.first == 'x' || it.first == '=') && it.second==0){
				throw "Invalid Equation.";
			}
		}
		catch(const char* msg){
			cout<<msg<<endl;
			return NULL;
		}
		if(it.first == 'l' && it.second>0){
			return new Task8(s);
		}
		else if(it.first == '(' && it.second>0){
			return new Exponential(s);
		}
		else if(it.first == '^' && it.second>0){
			return new Quadratic(s);
		}
		else if(it.first == ';' && it.second == 2){
			return new myTask(s);
		}
		else if(it.first == ';' && it.second == 1){
			return new task2(s);
		}
		else if(it.first == '|' && it.second > 0){
			return new Task9(s);
		}
	}
	cout<<"Invalid Equation."<<endl;
	return NULL;
}
int main(){
	string s;
	cin>>s;
	Equation* e = check_equation(s);
	if(e != nullptr){
		e->solve();
		e->print();
	}
	return 0;
}