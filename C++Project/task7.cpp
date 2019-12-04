#include<bits/stdc++.h>
using namespace std;
#include"task7.h"
#include"coefficients.h"
Exponential::Exponential(string s):Equation(s){x=0;}
Exponential::~Exponential(){
}
void Exponential::solve(){
	setCoefficients();
	double numerator = (coefficients_array[5]*log(coefficients_array[3]) - coefficients_array[2]*log(coefficients_array[0]));
	double denominator = (coefficients_array[1]*log(coefficients_array[0]) - coefficients_array[4]*log(coefficients_array[3]));
	try{
		if(denominator == 0){
			if(numerator == 0){
				throw "infinite solution.";
			}
			else{
				throw "no solution.";
			}
		}
		if(coefficients_array[0] <=0 || coefficients_array[3]<=0){
			throw "no solution.";
		}
	}
	catch(const char* msg){
		output=msg;
		flag = 1;
	}
	if(flag == 0){
		x = numerator/denominator;
	}
}
void Exponential::setCoefficients(){
	coefficients* c = new coefficients();
	int t = this->getEquation().find('=');
	lhs = this->getEquation().substr(1,t-1);
	rhs = this->getEquation().substr(t+1,(this->getEquation().size()-t-2));
	c->add_coefficients(lhs);
	c->add_coefficients(rhs);
	coefficients_array = c->get_coefficients();
}
double Exponential::gx(){
	return x;
}
ostream& operator<<(ostream& os,Exponential& e){
	if(e.flag == 0){
		os << "x="<<fixed<<setprecision(4)<<e.gx()<<endl;
		return os;
	}
	os<<e.output<<endl;
	return os;
}
void Exponential::print(){
	cout<<*this;
}