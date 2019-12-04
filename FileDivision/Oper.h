#ifndef X_H
#define X_H
#include<bits/stdc++.h>
using namespace std;
class Human
{
    public:
    int id;string name;
    static int count;
    static vector<int>myVector;
    Human();
    Human(int id,string name);
    friend ostream & operator << (ostream &out,Human &h);
   
};

#endif