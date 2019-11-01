#include"Project.h"
#include<bits/stdc++.h>

using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	int i;
	map<int,string>preOrderMap;
	map<int,int>inOrderMap;
	for(i=0;i<n;i++)
	{
		string x;
		cin>>x;
		preOrderMap[i]=x;
	}
	for(i=0;i<n;i++)
	{
		int x;
		cin>>x;
		inOrderMap[x]=i;
	}


	Node *mainroot;
	
	Node* finalRoot=mainroot->createTree(0,n-1,0,n-1,inOrderMap,preOrderMap);
	finalRoot->postOrderTraversal(finalRoot);
	cout<<endl;
}