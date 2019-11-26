#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include "node.h"
#define COUNT 10
using namespace std;

void levelOrder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	queue<Node*> Q;
	Q.push(root);

	//when there is one discovered node
	while (!Q.empty())
	{
		Node* current = Q.front();
		cout << endl
			<< current->id;
		if (current->left != NULL)
		{
			Q.push(current->left);
		}
		if (current->right != NULL)
		{
			Q.push(current->right);
		}
		Q.pop(); //removing the element at front
	}
}

Node* GetNewNode(string temp, int count)
{
	Node* NewNode = new Node();
	NewNode->data = temp;
	NewNode->id = count;
	NewNode->left = NULL;
	NewNode->right = NULL;
	return NewNode;
}

Node* Insert(Node* root, string temp, int count)
{
	//root->data = temp;
	if (root == NULL)
	{
		root = GetNewNode(temp, count);
		cout << root->id << " " << root->data << endl;

	}
	else if (count <= root->id)
	{
		root->left = Insert(root->left, temp, count);
	}
	else if (count > root->id)
	{
		root->right = Insert(root->right, temp, count);
	}
	return root;
}


void preOrder(Node* root) //function will keep calling itself
{
	if (root == NULL)
	{
		return;
	}
	cout << endl
		<< root->id;
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	inOrder(root->left);
	cout << endl
		<< root->id;
	inOrder(root->right);
}

void postOrder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout << endl << root->id;
}

void print2DUtil(Node *root, int space)
{
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += COUNT;

	// Process right child first
	print2DUtil(root->right, space);

	// Print current node after space
	// count
	cout<<endl;
	for (int i = COUNT; i < space; i++)
		{	
			cout<<" ";
		}
		cout<<root->id<<endl;

	// Process left child
	print2DUtil(root->left, space);
}

Node* findMin(Node* root)
{
	Node *_NR = new Node;
	if (root == NULL)
	{
		cout << endl << "The tree is empty.";
		return NULL;
	}
	else if (root->left == NULL)
	{
		return root;
	}
	else
	{
		findMin(root->left);
	}
}

Node* findMax(Node* root)
{
	Node *_NR = new Node;
	if (root == NULL)
	{
		cout << endl << "The tree is empty.";
		return NULL;
	}
	else if (root->right == NULL)
	{
		return root;
	}
	else
	{
		findMax(root->right);
	}
}
int findHeight(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int lHeight = findHeight(root->left);
		int rHeight = findHeight(root->right);

		if (lHeight > rHeight)
		{
			return lHeight;
		}
		else
		{
			return rHeight;
		}
	}
}

// Wrapper over print2DUtil()
void print2D(Node *root)
{
	// Pass initial space count as 0
	print2DUtil(root, 0);
}
bool search(Node* root, int data)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->id == data)
	{
		return true;
	}
	else if (data <= root->id)
	{
		return search(root->left, data);
	}
	else if (data > root->id)
	{
		return search(root->right, data);
	}
}


int main()
{
	Node *root = NULL;
	int choice = 0;
	int data = 0;
	bool flag = true;
	//attributes obj;

	do
	{
		cout << endl
			 << "Enter 1 for entering a value";
		cout << endl
			 << "Enter 2 for searching a value";
		cout << endl
			 << "Enter 3 for finding the minimum value";
		cout << endl
			 << "Enter 4 for finding the maximum value";
		cout << endl
			 << "Enter 5 for height of tree";
		cout << endl
			 << "Enter 6 for level order traversal";
		cout << endl
			 << "Enter 7 for Pre-Order traversal";
		cout << endl
			 << "Enter 8 for In-Order traversal";
		cout << endl
			 << "Enter 9 for Post-Order traversal";
		cout << endl
			 << "Enter 0 for exit";
		cout << endl
			 << "Choose an option: ";
		cin >> choice;
		if (choice == 1)
		{
			string temp[1728];
			ifstream File;
			File.open("car dataset.txt", ios::in);
			int i = 0;
			while (File >> temp[i])
			{
				root = Insert(root, temp[i], i);
				i++;
			}
			File.close();
		}
		
		else if (choice == 2)
		{
			int data;
			cout << endl
				 << "Enter the value you want to search: ";
			cin >> data;
			bool _flag = search(root, data);
			if (_flag == true)
			{
				cout << endl
					 << "Value found.";
			}
			else
			{
				cout << endl
					 << "Value not found.";
			}
		}
		
		else if (choice == 3)
		{
			Node *temp = new Node;
			temp = findMin(root);
			if (temp == NULL)
			{
				cout << endl << "The tree was empty." << endl;
			}
			else
			{
				cout << endl << "___________________________________" << endl;
				cout << temp->id << " " << temp->data << endl;
				cout << "___________________________________" << endl;
			}
		}
		else if (choice == 4)
		{
			Node *temp = new Node;
			temp = findMax(root);
			if (temp == NULL)
			{
				cout << endl << "The tree was empty." << endl;
			}
			else
			{
				cout << endl << "_______________________________________" << endl;
				cout << temp->id << " " << temp->data << endl;
				cout << "_______________________________________" << endl;
			}
		}
		else if (choice == 5)
		{
			cout << endl << findHeight(root);
		}
		else if (choice == 6)
		{
			levelOrder(root);
		}
		else if (choice == 7)
		{
			preOrder(root);
		}
		else if (choice == 8)
		{
			inOrder(root);
		}
		else if (choice == 9)
		{
			postOrder(root);
		}
		else if (choice == 11)
		{
			print2D(root);
		}
		else if (choice == 0)
		{
			flag = false;
		}
	} while (flag == true);
}