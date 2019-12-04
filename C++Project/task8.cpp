#include<bits/stdc++.h>
#include "task8.h"
#include"Equation.h"

using namespace std;
//Format : ln(ax+b) +ln(cx+d) =g
Task8 :: Task8(string s):Equation(s)
{   eq = s.substr(1,s.length()-2);
    a = 1;
    b =0 ;
    c =1;
    d = 0;
    g = 0;
    out = "";
}

int Task8 ::knowequation()
{   
    int firstx = eq.find("x");
    int secondx = eq.find("x",firstx+1); //search after firstx
    if(firstx==-1 && secondx==-1)
    {
        return 0; //No x
    } 
    else if(firstx==-1 || secondx==-1)
    {
        return 1; // 1 x
    } 
        return 2; // 2 x
}
void Task8 :: setCoefficients()
{
    if(knowequation()==1)
    {
        setcoefflinear();
    }
    else if(knowequation()==2)
    {  
        setcoeffquad();
    }
}
void Task8 :: solve()
{
    if(knowequation()==0)
    {
        out = "No Solution";
        return;
    }
    setCoefficients();
    double A = a*c;
    double B = b*c + a*d;
    double C = b*d - exp(g);
   //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<g<<endl;
   if(A==0)
   {    
        if(B!=0)
        {   double x = (-1*C)/B;
            x = round(x*10000)/10000;
            if(a*x+b<0)
                out ="invalid:x=";
            string s1= to_string(x);
                out = out + "x="+s1.substr(0,s1.length()-2);
        }
        else
            out = "No Solution";
   }
   else
   {
        double D = pow(B,2)-4*A*C;
        if(D<0)
        {
            out = "No Solution";
        }
        else
        {
            double x1 = (-1*B - sqrt(D))/(2*A);
            double x2 = (-1*B + sqrt(D))/(2*A);
            x1 = (round(x1*10000))/10000; 
            x2= (round(x2*10000))/10000;
            if(x1>x2) //for ascending order
            {
                double tmp = x2;
                x2 = x1;
                x1 = tmp;
            }
            int cnt = 0;
            string s1 = to_string(x1);
            string s2 = to_string(x2);
            if(a*x1+b<0 || c*x1+d<0)
            {
                if(a*x2+b<0 || c*x2+d<0)
                {
                    out = "invalid:x=" +s1.substr(0,s1.length()-2)+";";
                    out = out + "invalid:x="+s2.substr(0,s2.length()-2);   
                    return;    
                }     
                else
                {
                    out = "x="+s2.substr(0,s2.length()-2)+";";
                    out = out +"invalid:x=" +s1.substr(0,s1.length()-2);
                    return;
                }
            }
            else
            {
                out = "x=" +s1.substr(0,s1.length()-2)+";";  
                if(a*x2+b<0 || c*x2+d<0)
                {
                    out = out + "invalid:x="+s2.substr(0,s2.length()-2);   
                    return;    
                }
                else
                {
                    out = out+"invalid:x="+s2.substr(0,s2.length()-2);
                    return;
                }
            }
        }
   }
}

void Task8 :: setcoeffquad()
{   //set a and c --coeff of x
    int firstx = eq.find("x");
    int secondx =eq.find("x",firstx+1); 
    int start1=-1,start2=-1;
    int flag1 = -1;
    for(int i=firstx-1;i>=0;i--)
    {   
        if(eq[i]>='0'&&eq[i]<='9')
        {
            start1 = i;
        }
        else if(eq[i]=='-')
        {   
            start1 = i;
            if(i==firstx-1)
            {
                a = -1;
                start1=-1;
            }
            flag1=i;
            break;
        }
        else if(eq[i]=='+')
        {
            flag1 = i;
            break;
        }
        else
           break;
    }
    if(start1!=-1)
        a = stod(eq.substr(start1,firstx-start1));
    if(flag1!=-1)
        eq[flag1]='h';
 //   cout<<"a= "<<a<<endl;
    int flag2 = -1;
    for(int i=secondx-1;i>=0;i--)
    {   
        if(eq[i]>='0'&&eq[i]<='9')
        {   
            start2 = i;
        }
        else if(eq[i]=='-')
        {   
            start2 = i;
            if(i==secondx-1)
            {
                c = -1;
                start2=-1;
            }
            flag2 = i;
            break;
        }
        else if(eq[i]=='+')
        {
            flag2 = i;
            break;
        }
        else
            break;
    }
    if(start2!=-1)
        c = stod(eq.substr(start2,secondx-start2));
    if(flag2!=-1)
        eq[flag2]='h';
   // cout<<"c="<<c<<endl;
    //setting b
    int open1 = eq.find("(");
    int close1 = eq.find(")");
    if(eq[firstx+1]=='+' || eq[firstx+1]=='-') //if operand is there after x
    {
        b = stod(eq.substr(firstx+1,close1-firstx-1));
    }
    else
    {
        int operand = eq.find("h",open1);
        if(operand!=-1 && operand-open1>1)
        {
            b = stod(eq.substr(open1+1,operand-open1-1));
        }
        else
        {
            b = 0;
        }
    }
//    cout<<"b= "<<b<<endl;
    //setting d
    int close2 = eq.find(")",close1+1);
    int open2 = eq.find("(",close1+1); // ....)+ln(
    if(eq[secondx+1]=='+' || eq[secondx+1]=='-') //if operand is there after x
    {
        d = stod(eq.substr(secondx+1,close2-secondx-1));
    }
    else
    {
        int operand = eq.find("h",open2);
        if(operand!=-1 && operand-open2>1)
        {
            d = stod(eq.substr(open2+1,operand-open2-1));
        }
        else
        {
            d = 0;
        }
    }
//    cout<<"d="<<d<<endl;
    //setting g
    int pos = eq.find("=");
    g = stod(eq.substr(pos+1));
  //  cout<<"g= "<<g<<endl;
}
void Task8 :: setcoefflinear()
{   
    c = 0;
    int pos = eq.find("=");
    g = stod(eq.substr(pos+1));
    int firstln = eq.find("ln");
    int secondln = eq.find("ln",firstln+1);

    int posx = eq.find("x",secondln);
    int firstx,close,open,op,cl;
    if(posx==-1)
    {
        firstx = eq.find("x",firstln);
        open = eq.find("(",firstln);
        close = eq.find(")",firstln);
        op = eq.find("(",secondln);
        cl = eq.find(")",secondln);
    }
    else
    {   
        firstx = posx;
        open = eq.find("(",secondln);
        close = eq.find(")",secondln);
        op = eq.find("(",firstln);
        cl = eq.find(")",firstln);        
    }
    
    int start=-1;
    int flag = -1;
    for(int i=firstx-1;i>=0;i--)
    {   
        if(eq[i]>='0'&&eq[i]<='9')
        {
            start = i;
        }
        else if(eq[i]=='-')
        {   
            start = i;
            if(i==firstx-1)
            {
                a = -1;
                start=-1;
            }
            flag=i;
            break;
        }
        else if(eq[i]=='+')
        {
            flag = i;
            break;
        }
        else
           break;
    }
    if(start!=-1)
        a = stod(eq.substr(start,firstx-start)); 
    if(flag!=-1)
        eq[flag]='h';

    if(eq[firstx+1]=='+' || eq[firstx+1]=='-') //if operand is there after x
    {
        b = stod(eq.substr(firstx+1,close-firstx-1));
    }
    else
    {
        int operand = eq.find("h",open);
        if(operand!=-1 && operand-open>1)
        {
            b = stod(eq.substr(open+1,operand-open-1));
        }
        else
        {
            b = 0;
        }
    }
    d = stod(eq.substr(op+1,cl-op-1));
   // cout<<"a="<<a<<" "<<" b="<<b<<" c= "<<c<<" d= "<<d<<endl;
}
ostream & operator<<(ostream& os,Task8 &t)
{
    os<<t.out<<endl;
    return os;
}
void Task8:: print()
{    cout<<out<<endl;
}
Task8 :: ~Task8(){}