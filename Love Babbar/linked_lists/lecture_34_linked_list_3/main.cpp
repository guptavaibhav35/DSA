#include <iostream>
#include "Node.h"
#include "insertAtHead.h"
#include "insertAtPosition.h"
#include "insertAtTail.h"
#include "findLength.h"
#include "printList.h"
using namespace std;

int main()
{
    //**************************************************************************
    //*LinkedList-3*
    //**************************************************************************
    // The task here is to implement a

    // So lets first create 2 pointers for our linkedlist which are the head and tail of the linkedlist
    Node *head = NULL;
    Node *tail = NULL;

    //**************************************************************************
    //**Insertion at tail of the linkedlist**
    //**************************************************************************
    // Inserting elements at the tail of the linkedlist
    // For this we will be using the insertAtTail funtction which will help us to insert
    // elements at the tail of the linkedlist
    // This function has a void return type and also the arguments for this function
    // are head of the linkedlist, tail of the linkedlist and the data that has to be
    // inserted in the node of the linkedlist
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 70);

    //**************************************************************************
    //**Insertion at position in a linkedlist**
    //**************************************************************************
    // Inserting at a given position in the linkedlist
    // For this we are using the insertAtPosition function which as a void return type and takes in 4 parameters
    // the head , tail of the linkedlist and the data and position where the data has to be inserted
    insertAtPosition(head, tail, 25, 3);
    // Using the printList() function to print all the nodes of the linkedlist
    // This function has a void return type and only has one argument which is the
    // Head of the linkedlist. this will be used to traverse the linkedlist
    printList(head);

    //**************************************************************************
    //**Finding the middle node of the linkedlist**
    //**************************************************************************
    // So the main task here is to find the middle node of the linkedlist
    // So first check is the length of linkedlist is even or odd. for that we check use the findLength() function
    // to find the length of the linkedlist and then check is this lenth%2 is 0 or not
    // if yes then it means the linkedlist has even element else they have odd elements
    // so if the linkedlist has even elements then we use the findMiddleOfList() function which has a int return
    // type and takes in 2 parameters which is the
    if (findLength(head) % 2 == 0)
    {
        cout << findMiddleOfList(head, findLength(head) / 2);
    }
    else
    {
        cout << findMiddleOfList(head, (findLength(head) / 2) + 1);
    }

    // //**Creating a Circular Doubly inkedlist and performing all operations.
    // Node *head_circular = NULL;
    // insertInCircular(head_circular, 2023);
    // insertInCircular(head_circular, 2024);
    // insertInCircular(head_circular, 2025);
    // insertInCircular(head_circular, 2026);
    // insertInCircular(head_circular, 2027);
    // insertAfterDataCircular(head_circular, 2028, 2025);
    // cout << endl;
    // printCircular(head_circular);
    // cout << endl;
    // deleteFromCircular(head_circular, 2028);
    // printCircular(head_circular);
    // cout << endl;

    // //**Reversing Group of K Nodes in a LinkedList VVVVIMP**
    // printList(head);
    // head = reverseKNodes(head, 3);
    // printList(head);

    // //**Finding if a linkedList is Circular or Not**
    // cout << "Linkedlist is Circular or not? " << isCircular(head_circular)
    //      << endl;

    // // Finding Loops in LinkedLists using Maps
    // cout << "Finding Loops in Linkedlists using Maps" << endl;
    // Node *headLoop = new Node(10);
    // Node *first = new Node(20);
    // Node *second = new Node(30);
    // Node *third = new Node(40);
    // Node *fourth = new Node(50);
    // Node *fifth = new Node(60);
    // Node *sixth = new Node(70);
    // headLoop->next = first;
    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    // fifth->next = sixth;
    // sixth->next = third;
    // findLoopUsingMap(headLoop);

    // //**Finding Loops in LinkedLists using Floyd's Cycle Algorithm VVVIMP**
    // cout << "Finding Loops in Linkedlists using Floyd's Cycle Algorithm" << endl;
    // findLoopUsingFloyd(headLoop);

    // //**Finding starting point or node of loop in a LinkedList without using MAP VVVIMP**
    // cout << "the starting node of loop in a linkedList: " << findStartingNodeLoop(headLoop) << endl;

    // //**Removing the Loop from the LinkedList VVIMP**
    // removeLoop(headLoop);
    // printList(headLoop);
    // cout << findLoopUsingFloyd(headLoop);

    return 0;
}