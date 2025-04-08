#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	
	Node(int n)
	{
		data = n;
		left=right=NULL;
	}
};

Node* findSuccessor(Node* root)
{
	Node* curr = root->right;
	while(curr && curr->left)
	curr = curr->left;
	
	return curr;
}

Node* insert(Node* root,int key)
{
	if(root==NULL)
	return new Node(key);
	
	if(root->data>key)
	root->left=insert(root->left,key);
	
	else if(root->data<key)
	root->right=insert(root->right,key);
	
	return root;
}

void inorder(Node *root)
{
	if(root==NULL)
	return;
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

Node* deletion(Node* root,int key)
{
	if(root==NULL)
	return NULL;
	
	if(root->data>key)
	root->left = deletion(root->left,key);
	
	else if(root->data<key)
	root->right = deletion(root->right,key);
	
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			return NULL;
		}
		else if(root->left==NULL)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		
		else if(root->right==NULL)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		
		Node* successor = findSuccessor(root);
		root->data = successor->data;
		root->right = deletion(root->right,successor->data);
	}
}


int main()
{
	Node* root=NULL;
	
	root = insert(root,23);
	root = insert(root,15);
	root = insert(root,96);
	root = insert(root,7);
	root = insert(root,20);
	root = insert(root,88);
	root = insert(root,101);
	
	root = deletion(root,23);
	
	inorder(root);
}