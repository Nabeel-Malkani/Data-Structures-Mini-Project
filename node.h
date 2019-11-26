#ifndef Node_H
#define Node_H
#include <string>
using namespace std;

//structure for the type of data we are dealing with
struct attributes
{
	string data;    //This attribute is to be confirmed yet by Ma'am Sobia
};


//Tree of the data we are dealing with
struct Node
{
	int id;
	string data;
	Node* left;
	Node* right;
};

#endif