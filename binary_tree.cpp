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
	void destroy();
	void insert(node *leaf, int data);
	node *search(node *leaf, int data);
	void del(node *leaf, int data);
	void inorder(node *leaf);
	void postorder(node *leaf);
	void preorder(node *leaf);
	node *root;

public:

	B_Tree()
		{
			root = NULL;
		}
	void destroy()
	{
	}
	void insert(node *leaf, int data)
	{
		if (data < leaf->data)
		{
			if (leaf->left != NULL)
			{
				insert(leaf->left, data);
			}
			else
			{
				leaf->left = new node;
				leaf->left->data = data;
				leaf->left->left = NULL;
				leaf->left->right = NULL;
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
				leaf->right = new node;
				leaf->right->data = data;
				leaf->right->left = NULL;
				leaf->right->right = NULL;
			}
		}
	}

	void insert(int data)
		{
		if(root != NULL)
			{
				insert(root, data);
			}
		else
			{
				node* root = new node;
				root->data = data;
				root->left = NULL;
				root->right = NULL;
			}
		}

	node* search(int data, node* leaf)
		{
		if(leaf != NULL)
			{
			if(data == leaf->data)
				{
					return leaf;
				}
			else if(data < leaf->data)
				{
					return search(data, leaf->left);
				}
			else
				{
					return search(data, leaf->right);
				}
			}
		else
			return NULL;
		}
	node* search(int data)
		{
			return search(data, root);
		}

	void in_order()
		{
		inorder(root);
		cout<<"\n";
		}
	void inorder(node* leaf)
		{
		if(leaf != NULL)
			{
				inorder(leaf->left);
				cout << leaf->data<<",";
				inorder(leaf->right);
			}
		}
	void preorder()
		{
			preorder(root);
			cout << "\n";
		}
	void preorder(node* leaf)
		{
		if(leaf != NULL)
			{
			cout << leaf->data << ",";
			inorder(leaf->left);
			inorder(leaf->right);
			}
		}
	void postorder()
		{
			postorder(root);
			cout << "\n";
		}
	void postorder(node* leaf)
		{
		if(leaf != NULL)
			{
				inorder(leaf->left);
				inorder(leaf->right);
				cout << leaf->data<<",";
		    }
		}
};