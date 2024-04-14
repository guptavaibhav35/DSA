#include <iostream>
#include "Node.h"
using namespace std;

// Initializing a class Node to create a double linkedlist
// This is a double linkedlist so it will have 3 data members: data, next pointer and previous pointer.

// Constructor for this class node, this is the default constructor that will be called
// whenever a new object of the class Node is created.
// Since this is the default constructor, this will help us to initialize the
// Data members of the class Node with some default values
Node::Node()
{
    // Setting the value of data of the object to 0
    this->data = 0;
    // Setting the next pointer of the object to NULL
    this->next = NULL;
    // Setting the previous pointer of the object to NULL
    this->prev = NULL;
}

// This is another constructor in which we are getting an argument which is the
// data for the object or node in this case
// So here we will be setting the data of this object or node in this case to
// the value of this argument and will set the next and previous pointer to NULL
Node::Node(int val)
{
    // Setting the data of this object equal to val
    this->data = val;
    // Setting the next pointer of the object to NULL
    this->next = NULL;
    // Setting the prev pointer of the object to NULL
    this->prev = NULL;
}

// This is the destructor for this class
// This will be called whenever we want to delete the object of this class
// It will delete that object and will also print a message that the object
// or node in this case has been deleted
Node::~Node()
{
    // Displaying the message that the node has been deleted.
    cout << "Node is deleted" << endl;
}
