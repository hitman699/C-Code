#include<bits/stdc++.h>
#define pb push_back
using namespace std;
class Data
{
	public:
		string name;	       
		const int index;	
		Data(string name,int val) : index(val)
		{
			this->name=name;
		}
	friend class Node;
};

class Node
{
	private:
		Node *right;
		Node *left;
		Data *data;
	public:
		Node(string name,int index)
		{
			this->right=NULL;
			this->left=NULL;
			this->data=new Data(name,index);
		}
		//N LOG N CREATION
		Node* createTree(int preOrderStart,int preOrderEnd,int inOrderStart,int inOrderEnd,map<int,int>&inOrderMap,map<int,string>&preOrderMap)
		{
			string rootData=preOrderMap[preOrderStart];
			Node *(root)=new Node(rootData,preOrderStart);

			if(preOrderStart==preOrderEnd && inOrderStart==inOrderEnd)
			{
				root->right=NULL;
				root->left=NULL;
				return root;
			}

			int findInInorder=inOrderMap[preOrderStart];

			root->left  = createTree(preOrderStart+1,preOrderStart+findInInorder-inOrderStart,inOrderStart,findInInorder-1,inOrderMap,preOrderMap);
			root->right = createTree(preOrderStart+findInInorder-inOrderStart+1,preOrderEnd,findInInorder+1,inOrderEnd,inOrderMap,preOrderMap);
			return root;
		}
		void postOrderTraversal(Node* node)
		{
			if(node->left!=NULL)
			{
				postOrderTraversal(node->left);
			}
			if(node->right!=NULL)
			{
				postOrderTraversal(node->right);
			}
			cout<<node;
		}
		friend ostream & operator << (ostream &output,Node *n1);
};

ostream & operator << (ostream &output,Node *n1)
{
	output<<n1->data->index<<" "<<n1->data->name<<" ";
	return output;
}
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
