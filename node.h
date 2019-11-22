#ifndef Node_H
#define Node_H
#include <string>
using namespace std;

//structure for the type of data we are dealing with
struct attributes
{
    int id;
    string buying;
    string maintenence;
    int doors;
    int persons;
    string turbo;
    string safety;
    string unknown;     //This attribute is to be confirmed yet by Ma'am Sobia
};


//Tree of the data we are dealing with
struct Node
{
    int data;
    attributes object;
	Node *left;
	Node *right;
};

#endif