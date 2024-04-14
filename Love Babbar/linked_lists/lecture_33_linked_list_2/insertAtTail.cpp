#include <iostream>
#include "insertAtTail.h"
#include "Node.h"
using namespace std;

//**************************************************************************
//**Insertion at the tail of the linkedlist*
//**************************************************************************
// The main task here is to insert a node at the tail of the linkedlist
// this function has a void return type and takes in 3 arguments which are
// the head of the linkedlist, the tail of the linkedlist and the data that has to be
// entered in the new node of the linkedlist
// The main intuition here is to first check if this is our first node or not
// for that we will check if the head and the tail of the linkedlist are pointing to null
// or not, if yes then this is our first node of the linkedlist and is no different from just creating a new node
// so for that we will just create a new node and assign the new node its data,
// and now since this is our first node, then it means the head and tail of the linkedlist
// will be this new node, so we will make the head and the tail pointer point to this new node
// And if this condition is false, i.e., this is not our first node then it means there are some node
// already present in the linkedlist
// So for that we already know the tail of the linkedlist, so we will just create a new node
// we will make the next of the current tail point to this new node, and make the prev of this
// new node point to the current tail of the doubly linkedlist
// Then since this new node is the last node in the linkedlist, we will make
// the temp point to this new node
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // Checking if this is the first node of the linkedlist by checking if the head and tail
    // of the linkedlist are equal to NULL or not?
    if (head == NULL && tail == NULL)
    {
        // If yes then this is our first node in the linkedlist
        // creating a new node temp and also initializing the data for the new node
        Node *temp = new Node(data);
        // making the tail of the linkedlist point to this new node temp
        tail = temp;
        // Making the head of the linkedlist point to this new node temp
        head = temp;
    }
    // If this is not the first node in the linkedlist
    else
    {
        // Then creating a new node temp and also initializing the data for the new node
        Node *temp = new Node(data);
        // Making the next of the current tail point to this new node temp
        tail->next = temp;
        // Making the prev of this new node temp point to the current tail
        temp->prev = tail;
        // Making the tail point to this new node temp
        tail = temp;
    }

    // Printing a confirmation message that a new node has been inserted at the tail of the linkedlist
    cout << "A new node has been inserted at the tail of the linkedlist" << endl;
}