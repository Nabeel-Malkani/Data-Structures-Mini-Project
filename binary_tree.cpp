#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

class B_Tree
{
private:
	node *root;
	void destroy();
	void insert(node *root, int data);
	node *search(node *root, int data);
	void del(node *root, int data);
	void inorder(node *root);
	void postorder(node *root);
	void preorder(node *root);

public:
	void destroy()
	{
	}
	void insert(node *root, int data)
	{
		if (data < root->data)
		{
			if (root->left != NULL)
			{
				insert(root->left, data);
			}
			else
			{
				node *temp = new node;
				temp->data = data;
				temp->left = NULL;
				temp->right = NULL;
			}
		}
		else if (data > root->data)
		{
			if (root->right != NULL)
			{
				insert(root->right, data);
			}
			else
			{
				node *temp = new node;
				temp->data = data;
				temp->left = NULL;
				temp->right = NULL;
			}
		}
	}
};