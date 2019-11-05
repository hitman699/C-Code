#include<bits/stdc++.h>
#define pb push_back
using namespace std;

class Product
{
    public:
        string name;
        int total;
        Product(string name,int total)
        {
            this->name=name;
            this->total=total;
        }
        
};
bool comp(Product p1,Product p2)
{
    if(p1.total > p2.total)
        return 1;
    return 0;
}

class Bakery
{
    public:
    vector<Product>bakeryItems;
    Bakery(string name,int total)
    {
        Product p1(name,total);
        this->bakeryItems.pb(p1);
    }
    Bakery(){}
    void printValues()
    {
        sort(this->bakeryItems.begin(),this->bakeryItems.end(),comp);
        for(int i=0;i<this->bakeryItems.size();i++)
        {
            cout<<this->bakeryItems[i].name<<"  "<<this->bakeryItems[i].total<<endl;
        }
    }
};
class Dairy
{
    public:
    vector<Product>dairyItems;
    Dairy(string name,int total)
    {
        Product p1(name,total);
        this->dairyItems.pb(p1);
    }
    Dairy(){}
    void printValues()
    {
        sort(this->dairyItems.begin(),this->dairyItems.end(),comp);
         for(int i=0;i<this->dairyItems.size();i++)
        {
            cout<<this->dairyItems[i].name<<"  "<<this->dairyItems[i].total<<endl;
        }    
    }
};
class Store
{
    public:
    vector<Bakery>totalBakery;
    vector<Dairy>totalDairy;
    int bakerySize,dairySize;
    vector<Product>productList;
    Store(int bakerySize,int dairySize)
    {
        this->bakerySize=bakerySize;
        this->dairySize=dairySize;
        //DUMMY VALUES
        Bakery x;
        this->totalBakery.pb(x);
        Dairy y;
        this->totalDairy.pb(y);

        for(int i=1;i<=this->bakerySize;i++)
        {
            Bakery b1;
            this->totalBakery.pb(b1);
        }
        for(int i=1;i<=this->dairySize;i++)
        {
            Dairy d1;
            this->totalDairy.pb(d1);
        }
    }
    void addProduct(Product p)
    {
        this->productList.pb(p);
    }
    void printBakery()
    {
        for(int i=1;i<=this->bakerySize;i++)
        {
            cout<<"Bakery "<<i<<endl;
            this->totalBakery[i].printValues();
            cout<<endl;
        }
       
    }
    void printDairy()
    {
        for(int i=1;i<=this->dairySize;i++)
        {
            cout<<"Dairy "<<i<<endl;
            this->totalDairy[i].printValues();
            cout<<endl;
        }
    }
    void compute()
    {
        int checkBakery=1;
        int checkDairy=1;
        for(int i=0;i<this->productList.size();i++)
        {
            if(this->productList[i].name=="Bread")  //CALL BAKERY
            {
                if(checkBakery <=  this->bakerySize)
                {
                    Product p("Bread",this->productList[i].total);
                    this->totalBakery[checkBakery].bakeryItems.pb(p);
                }
                else
                {
                    checkBakery=1;
                    Product p("Bread",this->productList[i].total);
                    this->totalBakery[checkBakery].bakeryItems.pb(p);
                }
                
                checkBakery++;
            }
            else if(this->productList[i].name=="Cake")  //CALL BAKERY
            {
                if(checkBakery <=  this->bakerySize)
                {
                    Product p("Cake",this->productList[i].total);
                    this->totalBakery[checkBakery].bakeryItems.pb(p);
                }
                else
                {
                    checkBakery=1;
                    Product p("Cake",this->productList[i].total);
                    this->totalBakery[checkBakery].bakeryItems.pb(p);
                }
               
                checkBakery++;
            }
            else if(this->productList[i].name=="Muffin")  //CALL BAKERY
            {
                if(checkBakery <=  this->bakerySize)
                {
                    Product p("Muffin",this->productList[i].total);
                    this->totalBakery[checkBakery].bakeryItems.pb(p);
                }
                else
                {
                    checkBakery=1;
                    Product p("Muffin",this->productList[i].total);
                    this->totalBakery[checkBakery].bakeryItems.pb(p);
                }
              
                checkBakery++;
            }
            else if(this->productList[i].name=="Milk")   //CALL DAIRY
            {
                if(checkDairy <=  this->dairySize)
                {
                    Product p("Milk",this->productList[i].total);
                    this->totalDairy[checkDairy].dairyItems.pb(p);
                }
                else
                {
                    checkDairy=1;
                    Product p("Milk",this->productList[i].total);
                    this->totalDairy[checkDairy].dairyItems.pb(p);
                }
                
                checkDairy++;
            }
            else if(this->productList[i].name=="Butter")  //CALL DAIRY
            {
                if(checkDairy <=  this->dairySize)
                {
                    Product p("Butter",this->productList[i].total);
                    this->totalDairy[checkDairy].dairyItems.pb(p);
                }
                else
                {
                    checkDairy=1;
                    Product p("Butter",this->productList[i].total);
                    this->totalDairy[checkDairy].dairyItems.pb(p);
                }
                
                checkDairy++;
            }
        }
    }
};
int32_t main()
{
    int n,m;
    cin>>n>>m;
    Store s1(n,m);  //n=Bakeries m=Dairies
    while(1)
    {
        string name;
        int capacity;
        cin>>name;
        if(name=="End")
            break;
        else
        {
            cin>>capacity;
            Product p1(name,capacity);
            s1.addProduct(p1);
        }
    }
    cout<<s1.bakerySize<<"  "<<s1.dairySize<<endl;
    s1.compute();
    s1.printBakery();
    s1.printDairy();
}