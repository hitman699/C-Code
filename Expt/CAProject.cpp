#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;


int32_t main()
{
    //FORMAT(R) OPERATION REG1 REG2 REG3 SHAMT FUNC
    //FORMAT(I) OPERATION REG1 REG2 IMMEDIATE
    vector<vector<string>>instructionSet;

    map<string,int>opcode;              //instruction and opcode
    map<string,int>regValues;           //regValues and its opcode
    map<string,int>functionValues;      //operation and its opcode
    map<string,int>shamtValues;         //operation and its opcode

    opcode["add"]=0; 
    opcode["sub"]=0;
    opcode["mul"]=0;
    opcode["and"]=0;
    opcode["or"]=0; 
    opcode["div"]=0; 
    opcode["sll"]=0; 
    opcode["srl"]=0; 
    opcode["sra"]=0;

    opcode["lw"]=35;
    opcode["sw"]=43;
    opcode["addi"]=8;
    opcode["beq"]=4;
    opcode["bne"]=5;

    opcode["j"]=2;

    shamtValues["add"]=0;
    shamtValues["sub"]=0;
    shamtValues["mul"]=0;
    shamtValues["and"]=0;
    shamtValues["or"]=0;
    shamtValues["div"]=0;
    shamtValues["sll"]=4;
    shamtValues["srl"]=4;
    shamtValues["sra"]=4;

    regValues["$zero"]=0;
    regValues["s0"]=16;
    regValues["s1"]=17;
    regValues["s2"]=18;
    regValues["s3"]=19;
    regValues["s4"]=20;
    regValues["s5"]=21;
    regValues["s6"]=22;
    regValues["s7"]=23;


    regValues["t0"]=8;
    regValues["t1"]=9;
    regValues["t2"]=10;
    regValues["t3"]=11;
    regValues["t4"]=12;
    regValues["t5"]=13;
    regValues["t6"]=14;
    regValues["t7"]=15;

    functionValues["add"]=32;
    functionValues["sub"]=34;
    functionValues["mul"]=24; 
    functionValues["and"]=36;
    functionValues["or"]=37;
    functionValues["div"]=26;
    functionValues["sll"]=0;
    functionValues["srl"]=2;
    functionValues["sra"]=3;
   
    while(1)
    {
        string operation;
        cin>>operation;
        if(operation=="##")
        {
            break;
        }
        else if(operation=="add" || operation=="mul" || operation=="sub" || operation=="and" || operation=="or")
        {
            string format="R";
            string reg1,reg2,reg3;
            cin>>reg1>>reg2>>reg3;
            vector<string>temp;
            temp.pb(format);
            temp.pb(reg1);
            temp.pb(reg2);
            temp.pb(reg3);
            instructionSet.pb(temp);
        }
        else if(operation=="lw" || operation=="sw" || operation=="addi")
        {
            string format="I";
            string reg1,reg2;
            cin>>reg1>>reg2;
            string immediate;
            cin>>immediate;
            vector<string>temp;
            temp.pb(format);
            temp.pb(reg1);
            temp.pb(reg2);
            temp.pb(immediate);
            instructionSet.pb(temp);
        }
    }
}