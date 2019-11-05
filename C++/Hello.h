#ifndef HELLO_H
#define HELLO_H
#include<bits/stdc++.h>
#define pb push_back
using namespace std;

class Product
{
    public:
        string name;
        int total;
        Product(string name,int total);
};
bool comp(Product p1,Product p2);

class Bakery
{
    public:
    vector<Product>bakeryItems;
    Bakery(string name,int total);
    Bakery();
    void printValues();
};
class Dairy
{
    public:
    vector<Product>dairyItems;
    Dairy(string name,int total);
    Dairy();
    void printValues();
};
class Store
{
    public:
    vector<Bakery>totalBakery;
    vector<Dairy>totalDairy;
    int bakerySize,dairySize;
    vector<Product>productList;
    Store(int bakerySize,int dairySize);
    void addProduct(Product p);
    void printBakery();
    void printDairy();
    void compute();
};
#endif