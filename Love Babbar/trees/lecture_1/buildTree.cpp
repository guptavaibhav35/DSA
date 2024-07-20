#include <bits/stdc++.h>
using namespace std;

//**************************************************************************
//*Creating the class Node*
//**************************************************************************
// Creating the class Node that will help us store the data of the tree

class Node
{
    // Creating public data members of the class Node to store the data of the
    // tree
public:
    // This will store the value of the node of the tree
    int data;
    // This will store the left child of the tree
    Node *left;
    // This will store the right child of the tree
    Node *right;

    // Defining the constructor of the class Node, it has one parameter which is
    // the data of the node of the tree
    Node(int data)
    {
        // Assigning the data passed to the data member of the object of class Node;
        this->data = data;
        // Initializing the left and right child of the tree to NULL
        left = NULL;
        right = NULL;
    }
};

//**************************************************************************
//*Build Tree*
//**************************************************************************
// This function will help us to build or contruct a tree, it has no parameter
// and has a Node return type.
// At the end it will return the root of the tree built.
Node *buildTree()
{
    // Displaying message to the user to enter the data of the node of the tree
    cout << "Enter the data of the node: ";
    // Creating a data variable to store the data of the node of the tree
    int data;
    // storing the data entered by the user in the data variable
    cin >> data;

    // Checking if the data entered by the user is -1 or not?
    if (data == -1)
    {
        // If yes then it means there is no node and we have to return NULL
        return NULL;
    }
    // If here then it means that the data entered by the user is not -1
    else
    {
        // Creating a new node of the tree with the data entered by the user
        Node *node = new Node(data);
        // Displaing message to the user to enter the left child of the node of the
        // tree
        cout << "Enter the data of the left child of the " << data << " node: ";
        // calling the buildTree() to build the left child of the node of the tree
        node->left = buildTree();
        // Displaying message to the user to enter the right child of the node of
        // the tree
        cout << "Enter the data of the right child of the " << data << " node: ";
        // Calling the buildTree() to build the right child of the node of the tree
        node->right = buildTree();
        // Returning the node of the tree
        return node;
    }
}