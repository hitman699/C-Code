#include<bits/stdc++.h>
using namespace std;
class Pixel
{
    private:
        int iloc,jloc;
        char mark;
    public:
    Pixel(int iloc,int jloc,char mark)
    {
        this->iloc=iloc;
        this->jloc=jloc;
        this->mark=mark;
    }
    int returnIloc()
    {
        return this->iloc;
    }
    int returnJloc()
    {
        return this->jloc;
    } 
    char returnMark()
    {
        return this->mark;
    }
    void changeMark(char x)
    {
        this->mark=x;
    }
};
class Image
{
    public:
    int rows,cols;
    vector<vector<Pixel>>a;
    Image(int rows,int cols)
    {
        this->rows=rows;
        this->cols=cols;
        this->a;   //USE VECTOR OF PIXELS
        for(int i=0;i<this->rows;i++)
        {
            vector<Pixel>temp;
            for(int j=0;j<this->cols;j++)
            {
                Pixel p1(i,j,'o');
                temp.push_back(p1);
            }
            this->a.push_back(temp);
        }
    }
    void addPixel(Pixel p1,int width)
    {
            width++;
            int centerX=p1.returnIloc();
            int centerY=p1.returnJloc();
            char x=p1.returnMark();
            this->a[centerX][centerY].changeMark('x');
            int presentW=width;
            for(int j=centerY;j>=0 && presentW!=0 ;j--)
            {
                for(int i=centerX;i<centerX+presentW && i<this->cols;i++)
                {
                    this->a[i][j].changeMark('x');
                }
                for(int i=centerX;i>centerX-presentW && i>=0;i--)
                {
                    this->a[i][j].changeMark('x');
                }
                presentW--;
            }

            presentW=width;
            for(int j=centerY;j<this->cols && presentW!=0 ;j++)
            {
                for(int i=centerX;i<centerX+presentW && i<this->cols;i++)
                {
                    this->a[i][j].changeMark('x');
                }
                for(int i=centerX;i>centerX-presentW && i>=0;i--)
                {
                    this->a[i][j].changeMark('x');
                } 
                presentW--;
            }
        
    }
    void printImage()
    {
        for(int i=0;i<this->a.size();i++)
        {
            for(int j=0;j<this->a[i].size();j++)
            {
                cout<<this->a[i][j].returnMark()<<" ";
            }
            cout<<endl;
        }
    }
};
int32_t main()
{
    int n,m;
    cin>>n>>m;
    Image i1(n,m);
   
    while(1)
    {
        int x,y,w;
        cin>>x;
        if(x==-1)
            break;
        else
        {
            cin>>y>>w;
            Pixel p1(x,y,'x');
            i1.addPixel(p1,w);
        }
    }
    i1.printImage();
}