#include"Project.h"
#include<bits/stdc++.h>
using namespace std;

		Data::Data(string name,const int val) : index(val)
		{
			this->name=name;
		}

		Node::Node(string name,int index)
		{
			this->right=NULL;
			this->left=NULL;
			this->data=new Data(name,index);
		}
		Node* Node::createTree(int preOrderStart,int preOrderEnd,int inOrderStart,int inOrderEnd,map<int,int>&inOrderMap,map<int,string>&preOrderMap)
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
		void Node::postOrderTraversal(Node* node)
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

		ostream & operator << (ostream &output,Node *n1)
		{
			output<<n1->data->index<<" "<<n1->data->name<<" ";
			return output;
		}
