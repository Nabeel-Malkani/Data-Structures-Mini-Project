#include <iostream>
#include <queue>

using namespace std;

struct Node		//tree structure
{
	int data;
	Node *left;
	Node *right;
};

void levelOrder (Node* root)
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
			cout << endl << current->data;
			if (current->left != NULL)
			{
				Q.push(current->left);
			}
			if (current->right != NULL)
			{
				Q.push(current->right);
			}
			Q.pop();		//removing the element at front
	}
}

Node *GetNewNode(int data)
{
	Node *NewNode = new Node();
	NewNode->data = data;
	NewNode->left = NULL;
	NewNode->right = NULL;
	return NewNode;
}

Node *Insert(Node *root, int data)
{
	if (root == NULL)
	{
		root = GetNewNode(data);
	}
	else if (data <= root->data)
	{
		root->left = Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
}

void preOrder(Node* root)  //fuction will keep calling itself
{
	if (root == NULL)
	{
		return;
	}
	cout << endl << root->data;
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node* root)
{
	if (root == NULL){return;}
	inOrder(root->left);
	cout << endl << root->data;
	inOrder(root->right);
}

void postOrder(Node* root)
{
	if(root == NULL){return;}
	postOrder(root->left);
	postOrder(root->right);
	cout << endl << root->data;
}

int findMin(Node *root)
{
	if (root == NULL)
	{
		cout << endl << "The tree is empty.";
		return -1;
	}
	else if (root->left == NULL)
	{
		return root->data;
	}
	else
	{
		findMin(root->left);
	}
}

int findMax(Node *root)
{
	if (root == NULL)
	{
		cout << endl << "The tree is empty.";
	}
	else if (root->right == NULL)
	{
		return root->data;
	}
	else
	{
		findMax(root->right);
	}
}

int findHeight(Node* root)
{
	int lHeight = 0, rHeight = 0;
	if (root == NULL)
	{
		cout << endl << "The tree is empty.";	
	}
	else
	{
		lHeight = findHeight(root->left);
		rHeight = findHeight(root->right);
	}

	if (lHeight > rHeight || lHeight == rHeight)
	{
		return lHeight + 1;
	}
	else
	{
		return rHeight + 1;
	}
}

bool search(Node *root, int data)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->data == data)
	{
		return true;
	}
	else if (data <= root->data)
	{
		return search(root->left, data);
	}
	else if (data >= root->data)
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
	do
	{
		cout << endl << "Enter 1 for entering a value";
		cout << endl << "Enter 2 for searching a value";
		cout << endl << "Enter 3 for finding the minimum value";
		cout << endl << "Enter 4 for finding the maximum value";
		cout << endl << "Enter 5 for height of tree";
		cout << endl << "Enter 6 for level order traversal";
		cout << endl << "Enter 7 for Pre-Order traversal";
		cout << endl << "Enter 8 for In-Order traversal";
		cout << endl << "Enter 9 for Post-Order traversal";
		cout << endl << "Enter 0 for exit";
		cout << endl << "Choose an option: ";
		cin >> choice;
		if (choice == 1)
		{
			cout << endl << "Enter the value you want to insert: ";
			cin >> data;
			root = Insert(root, data);
		}
		else if (choice == 2)
		{
			cout << endl << "Enter the value you want to search: ";
			cin >> data;
			flag = search(root, data);
			if (flag == true)
			{
				cout << endl << "Value found.";
			}
			else
			{
				cout << endl << "Value not found.";
			}
		}
		else if (choice == 3)
		{
			cout << endl << findMin(root);
		}
		else if (choice == 4)
		{
			cout << endl << findMax(root);
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
		else if (choice == 0)
		{
			flag = false;
		}
	}while (flag == true);
	system("Pause");
}