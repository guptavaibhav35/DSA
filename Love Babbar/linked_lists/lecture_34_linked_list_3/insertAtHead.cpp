#include <iostream>
#include "Node.h"
#include "insertAtHead.h"
using namespace std;

//**************************************************************************
//**Insertion at the head of the linkedlist*
//**************************************************************************
// The main task here is to insert a node at the head of the linkedlist
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
// already present in the linkedlist and we have to insert a new node at the head of the linkedlist
// so for that we will first create a new node and then make the next of this new node point to
// the current head of the linkedlist and make the prev of the current head point to this new node
// and at last we will make the head of the linkedlist point to this new node of the linkedlist
// this way we have inserted a new node at the head of the linkedlist
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // Checking if this is our first node or not? for this we are comparing if the head and tail
    // of the current linkedlist point to NULL or not?
    if (head == NULL && tail == NULL)
    {
        // If yes then this is our very first node in the linkedlist,
        // So we will first create a new node and also assign it with the data
        Node *temp = new Node(data);
        // Then we will make the tail point to this new node temp
        tail = temp;
        // Also we will make the head point to this new node temp
        head = temp;
        // printing a confirmation message that a new node has been inserted at the head of the linkedlist
        cout << "A new node has been inserted at the head of the linkedlist" << endl;
        // And since now no more operations are needed so we will return back to the function call
        return;
    }
    // If this is not the first node then we already have some nodes in the linkedlist
    else
    {
        // So we will first create a new node temp and also give it the data
        Node *temp = new Node(data);
        // Then we will make the next of the new node temp point to the current head of the LL
        temp->next = head;
        // Then we will make the prev of the current head of the linkedlist point to this new node temp
        head->prev = temp;
        // then we will make the current head of the linkedlist point to this new node temp so that this is our updated head
        head = temp;
        // printing a confirmation message that a new node has been inserted at the head of the linkedlist
        cout << "A new node has been inserted at the head of the linkedlist" << endl;
        // And since now no more operations are needed so we will return back to the function call
        return;
    }
}