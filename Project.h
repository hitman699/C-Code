#ifndef PROJECT_H
#define PROJECT_H

#include<bits/stdc++.h>
using namespace std;
class Data
{
	public:
		string name;	       
		const int index;	
		Data(string name,const int val); //: index(val){};
	friend class Node;
};

class Node
{
	private:
		Node *right;
		Node *left;
		Data *data;
	public:
		Node(string name,int index);
		void postOrderTraversal(Node* node);
		Node* createTree(int preOrderStart,int preOrderEnd,int inOrderStart,int inOrderEnd,map<int,int>&inOrderMap,map<int,string>&preOrderMap);
		friend ostream & operator << (ostream &output,Node *n1);
};
ostream & operator << (ostream &output,Node *n1);
#endif