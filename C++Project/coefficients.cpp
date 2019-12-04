#include "coefficients.h"
coefficients::coefficients(){
}
coefficients::~coefficients(){}
void coefficients::add_coefficients(string s){
	string a = "",b = "",c = "";
	int p = 0,q = 0,r = 0,t = 0;//p:^,q:(,r:x,s:),t:=,u:+,-
	p = s.find('^');
	q = s.find('(');
	r = s.find('x');
	t = s.find(')');
	if(p == -1){
		a = s;
		b = "0";
		c = "1";
	}
	else{
		a = s.substr(0,p);
		if(r == t-1){
			for(int i = r-1;i>q;i--){
				if(s[i] == '+' || s[i] == '-'){
					b = s.substr(i,r-i);
					c = s.substr(q+1,i-q-1);
					break;
				}
			}
		}
		else{
			if(r == -1){
				b = "0";
				c = s.substr(q+1,t-q-1);	
			}
			else{
				b = s.substr(q+1,r-q-1);
				c = s.substr(r+1,t-r-1);
			}
		}
		if(c == ""){
			b = s.substr(q+1,r-q-1);
			c = "0";
		}
		if(b == "" || b == "-"){
			b +='1';
		}
	}
	coefficients_array.push_back(stod(a));
	coefficients_array.push_back(stod(b));
	coefficients_array.push_back(stod(c));
}
vector<double> coefficients::get_coefficients(){
	return coefficients_array;
}
