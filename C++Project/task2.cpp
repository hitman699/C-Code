#include<iostream>
#include"task2.h"
using namespace std;

task2::task2(string s):Equation(s){
    a1 = 0;
    a2 = 0;
    b1 = 0;
    b2 = 0;
    c1 = 0;
    c2 = 0;
}
void task2::divide1(string eq,float &b,int i,int j)
{
    if(j-i-1==1&&eq[i]=='+')
    {
        b = 1;
    }
    if(j-i-1==1&&eq[i]=='-')
    {
        b = -1;
    }
    if(j-i-1>1)
    {
        b = stof(eq.substr(i,j-i-1));
    }
}
void task2::divide(string eq,float &a,float &b,float &c,int i)
{
            string temp = eq.substr(0,i-1);
            if(i-1==0)
            {
                a = 1;
            }
            else
            {
                if(i-1==1&&temp[0]=='-')
                {
                    a = -1;
                }
                else
                {
                    a = stof(temp);
                }
                
            }
            for(int j = i+1;j<eq.length();j++)
            {
                if(eq[j]=='=')
                {
                    divide1(eq,b,i,j);
                    c = stof(eq.substr(j+1,eq.length()-(j+1)));
                    break;
                }
                if((eq[j]=='-'&&eq[j-1]=='x')||(eq[j]=='-'&&eq[j-1]=='y'))
                {
                   int l = 0;
                   for(int k =j+1;l<eq.length();k++)
                   {
                       if(eq[k]=='=')
                       {
                           l =k;
                           break;
                       }
                   } 
                  divide1(eq,b,i,j);
                    c = stof(eq.substr(j+1,l-(j+1)));
                    break;   
                }
                if((eq[j]=='+'&&eq[j-1]=='x')||(eq[j]=='+'&&eq[j-1]=='y'))
                {
                    int l = 0;
                   for(int k =j+1;l<eq.length();k++)
                   {
                       if(eq[k]=='=')
                       {
                           l =k;
                           break;
                       }
                   } 
                    divide1(eq,b,i,j);
                    c = -stof(eq.substr(j+1,l-(j+1)));
                    break;
                }                
            }
}
void task2::parsing(string eq,float &a,float &b,float &c)
{
    for(int i =1;i<eq.length();i++)
    {
        if((eq[i]=='+'&&eq[i-1]=='x')||(eq[i]=='-'&&eq[i-1]=='x'))
        {
            divide(eq,a,b,c,i);
            break;
        }   
        if((eq[i]=='+'&&eq[i-1]=='y')||(eq[i]=='-'&&eq[i-1]=='y'))
        {
            divide(eq,b,a,c,i);
            break;
        }
    }
}
void task2::setCoefficients()
{
    parsing(eq1,a1,b1,c1);
    parsing(eq2,a2,b2,c2);
}
void task2::solve()
{
    //string eq1;
    //string eq2;
    int k =0;
    string tempeq = getEquation();
    string eq = tempeq.substr(1,tempeq.length()-2);
    for(k =0;k<eq.length();k++)
    {
        if(eq[k]==';')
        {   
            break;
        }
    }
    eq1 = eq.substr(0,k);
    eq2 = eq.substr(k+1,eq.length()-k-1);
    setCoefficients();
    //float a1=0,a2=0,b1=0,b2=0,c1=0,c2=0;
    
    x = (b2*c1-b1*c2)/(a1*b2-a2*b1);
    y = (a1*c2-a2*c1)/(a1*b2-a2*b1);
}
void task2::print(){
    cout<<*this;
}

ostream& operator<<(ostream& os, const task2& eq)
{
    os<<"x="<<eq.x<<";y="<<eq.y<<endl;
    return os;
}