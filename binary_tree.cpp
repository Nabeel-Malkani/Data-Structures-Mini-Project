#include<iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

class B_Tree{
	private:
		 node* root;
		 void destroy();
		 void insert(node*root, int data);
		 void search(node* root,int data);
		 void del(node* root,int data);
		 
		 
};