#include<bits/stdc++.h>
#define int double
#include"task5.h"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;


myTask::myTask(string x):Equation(x) //UNPARSED STRING
{
    x = x.substr(1,x.size()-2);
    stringstream check(x);
    string intermediate;
    while(getline(check,intermediate,';'))
    {
        this->equationList.pb(intermediate);
    } 
    this->setCoefficients();   
}
myTask::~myTask(){}

int myTask::solveDeterminant(vector<vector<int>>matrix)
{
    int a1,b1,c1,a2,b2,c2,a3,b3,c3;
    a1=matrix[0][0];
    b1=matrix[0][1];
    c1=matrix[0][2];
    a2=matrix[1][0];
    b2=matrix[1][1];
    c2=matrix[1][2];
    a3=matrix[2][0];
    b3=matrix[2][1];
    c3=matrix[2][2];
    
    
    int answer=a1*(b2*c3-c2*b3)-b1*(a2*c3-c2*a3)+c1*(a2*b3-b2*a3);
    return answer;
}
void myTask::solve()
{
    vector<vector<int>>D;
    vector<vector<int>>DX;
    vector<vector<int>>DY;
    vector<vector<int>>DZ;
    
    D.pb(this->a);
    D.pb(this->b);
    D.pb(this->c);
    DX.pb(this->d);
    DX.pb(this->b);
    DX.pb(this->c);
    DY.pb(this->a);
    DY.pb(this->d);
    DY.pb(this->c);
    DZ.pb(this->a);
    DZ.pb(this->b);
    DZ.pb(this->d);
   
    if(solveDeterminant(D)==0)
    {
        cout<<"Non-Unique Solution"<<endl;
        cout<<"One of the solutions is "<<endl;
        this->answerX=0;
        this->answerY=0;
        int lastInteger=this->d[this->d.size()-1];
        int lastCoefficient=this->c[this->c.size()-1];
        this->answerZ=lastInteger/lastCoefficient;

    }
    else
    {
    
        float x=solveDeterminant(DX)/solveDeterminant(D);
        float y=solveDeterminant(DY)/solveDeterminant(D);
        float z=solveDeterminant(DZ)/solveDeterminant(D);
      
        this->answerX=x;
        this->answerY=y;
        this->answerZ=z;
    }
   
}
void myTask::setCoefficients()
{
    //cout<<"Setting variables "<<endl;
    for(int i=0;i<this->equationList.size();i++)
    {
        
        for(int j=0;j<this->equationList[i].size();j++)
        {
            
            if(this->equationList[i][j]=='=')
            {
                int neg=0;
                string num="";
                
                for(int k=j+1;k<this->equationList[i].size();k++)
                {
                   
                    if(this->equationList[i][k]=='-')
                    {
                       
                        neg=1;
                    }
                    else
                    {
                       num.pb(this->equationList[i][k]); 
                    }
                }
               
                int x=stoi(num);
                if(neg==1)
                {
                    x=-x;
                }
              
                this->d.pb(x);
                
            }
            if(this->equationList[i][j]=='x')
            {
               
                int flag=0;
                string number="";
                int neg=0;
                for(int k=j-1;k>=0;k--)
                {
                   //Gone once into loop
                    if(this->equationList[i][k]=='+')
                    {
                        break;
                    }
                    else if(this->equationList[i][k]=='-')
                    {
                        neg=1;
                        break;
                    }
                    else
                    {
                        flag=1;
                        number.pb(this->equationList[i][k]);
                    }
                }
                if(flag==0)
                {
                    number.pb('1');
                }
                reverse(number.begin(),number.end());
                int x=stoi(number);
                if(neg==1)
                {
                    x=-x;
                }
                
                this->a.pb(x);
            }
            if(this->equationList[i][j]=='y')
            {
                
                int flag=0;
                string number="";
                int neg=0;
                for(int k=j-1;k>=0;k--)
                {
                   //Gone once into loop
                    if(this->equationList[i][k]=='+')
                    {
                        break;
                    }
                    else if(this->equationList[i][k]=='-')
                    {
                        neg=1;
                        break;
                    }
                    else
                    {
                        flag=1;
                        number.pb(this->equationList[i][k]);
                    }
                }
                if(flag==0)
                {
                    number.pb('1');
                }
                reverse(number.begin(),number.end());
                int x=stoi(number);
                if(neg==1)
                {
                    x=-x;
                }
              
                this->b.pb(x);
            }
            else if(this->equationList[i][j]=='z')
            {
              
                int flag=0;
                string number="";
                int neg=0;
                for(int k=j-1;k>=0;k--)
                {
                   //Gone once into loop
                    if(this->equationList[i][k]=='+')
                    {
                        break;
                    }
                    else if(this->equationList[i][k]=='-')
                    {
                        neg=1;
                        break;
                    }
                    else
                    {
                        flag=1;
                        number.pb(this->equationList[i][k]);
                    }
                }
                if(flag==0)
                {
                    number.pb('1');
                }
                reverse(number.begin(),number.end());
                int x=stoi(number);
                if(neg==1)
                {
                    x=-x;
                }
                this->c.pb(x);
            }
        }
    }
   // cout<<"Setting DONE!!!"<<endl;
}
void myTask::printVariables()
{
    cout<<"A"<<endl;
    for(int i=0;i<this->a.size();i++)
    {
        cout<<this->a[i]<<" ";
    }
    cout<<endl;
    cout<<"B"<<endl;
    for(int i=0;i<this->b.size();i++)
    {
        cout<<this->b[i]<<" ";
    }
    cout<<endl;
    cout<<"C"<<endl;
    for(int i=0;i<this->c.size();i++)
    {
        cout<<this->c[i]<<" ";
    }
    cout<<endl;
    cout<<"D"<<endl;
    for(int i=0;i<this->d.size();i++)
    {
        cout<<this->d[i]<<" ";
    }
    cout<<endl;
}
void myTask::print()
{
    cout<<*this;
}
ostream& operator<<(ostream& os,myTask& t)
{
    os<<"x="<<t.answerX<<";y="<<t.answerY<<";z="<<t.answerZ<<endl;
    return os;
}