#include <iostream>
#include "Node.h"
#include "printList.h"
#include "findLength.h"
#include "insertAtHead.h"
#include "insertAtTail.h"
#include "insertAtPosition.h"
#include "reverseLinkedList.h"
#include "deleteNode.h"
using namespace std;

int main()
{
    //**************************************************************************
    //*LinkedList-2*
    //**************************************************************************
    // The tasks here is to create a doubly linked list and insert elements into
    // list and print those elements.

    // So lets first create 2 pointers for our linkedlist which are the head and tail of the linkedlist
    Node *head = NULL;
    Node *tail = NULL;

    // Inserting elements at the tail of the linkedlist
    // For this we will be using the insertAtTail funtction which will help us to insert
    // elements at the tail of the linkedlist
    // This function has a void return type and also the arguments for this function
    // are head of the linkedlist, tail of the linkedlist and the data that has to be
    // inserted in the node of the linkedlist
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 70);

    // Using the printList() function to print all the nodes of the linkedlist
    // This function has a void return type and only has one argument which is the
    // Head of the linkedlist. this will be used to traverse the linkedlist
    printList(head);

    // Some more operations done on this doubly linkedlist
    // The operations are to insert at the head of linkedlist and at the tail of the linkedlist
    // to insert an element at the head of the linkedlist we will be using the
    // insertAtHead() which has a void return type and takes in 3 arguments
    // they are: the head of the linkedlist, the tail of the linkedlist and the
    // data that has to be inserted in the linkedlist as a new node
    insertAtHead(head, tail, 10010);
    insertAtTail(head, tail, 90);

    // using the printList() function again to print the updated linkedlist
    printList(head);

    // Inserting at a given position in the linkedlist
    // For this we are using the insertAtPosition function which as a void return type and takes in 4 parameters
    // the head , tail of the linkedlist and the data and position where the data has to be inserted
    insertAtPosition(head, tail, 2012, 3);

    // using the printList() function again to print the updated linkedlist
    printList(head);

    // Here we are using the deleteNode() to delete a node from a poistion in a linkedlist. it has a void return type and
    //  has 3 parameters: the head of the linkedlist, tail of the linkedlist and the position from where we want to delete the node
    deleteNode(head, tail, 9);

    // using the printList() function again to print the updated linkedlist
    printList(head);

    // Here we are using the reverseLinkedList() function to reverse the linkedlist, it has a void return type and takes in 3 parameters: the head of the
    // linkedlist, tail of the linkedlist, and the null pointer which is like the node to the left of the head of the linkedlist which is NULL.
    reverseLinkedList(head, head, NULL);

    // using the printList() function again to print the updated linkedlist
    printList(head);

    //****
    return 0;
}