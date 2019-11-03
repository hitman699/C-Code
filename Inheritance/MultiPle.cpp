#include<bits/stdc++.h>
using namespace std;
class Father
{
    public:
    int height;
    Father(int h)
    {
        this->height=h;
    }
};
class Mother
{
    public:
    string skinColor;
    Mother(string sk)
    {
        this->skinColor=sk;
    }
};
class Child : public Father,public Mother
{
    public:
    Child(string sk,int h):Father(h),Mother(sk)
    {
        cout<<"Child Constructor called"<<endl;
    }
    void display()
    {
        cout<<this->height<<"  "<<this->skinColor;
    }
};
int32_t main()
{
    Child c1("White",100);
    c1.display();
}