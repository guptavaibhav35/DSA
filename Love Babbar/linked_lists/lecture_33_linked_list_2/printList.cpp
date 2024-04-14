#include <iostream>
#include "Node.h"
#include "printList.h"
using namespace std;

//**************************************************************************
//*Printing the linkedlist*
//**************************************************************************
// This function will be used to print the nodes of this doubly linkedlist
// This function has a void return type and only has one parameter which is the
// head of the linked list
// So the main intuition or idea here is to first create a temp pointer of type Node
// so that we do not loose the track of the head of the linkedlist even if the
// head has been passed by value or reference
// Once the temp pointer has been created, we will assign it the value of pointer head
// Now this temp pointer will act as our new head
// Now we will use a loop like a while loop in this case, which will have the breakout condition
// of checking if the temp pointer is equal to NULL or not
// If yes then it means we are the end of the linkedlist and there are no more nodes
// in front of this pointer in the linkedlist
// If no we will print the data of the node on which temp is pointing and then move
// the temp one poisition to the right by assigning it the value of current node's next
// At the end of this function and also this loop we will have all the nodes of the doubly linkedlist printed on the console
void printList(Node *&head)
{
    // Creaiting the temp pointer of type node and assigning it the value of head
    Node *temp = head;

    cout << "Printing the doubly linkedlist: " << endl;
    // Using a while loop to iterate over the linkedlist
    // the breakout condition here is to check if the temp pointer is equal to null or not
    while (temp != NULL)
    {
        // if yes then this position of temp pointer is a valid node and has some data
        // printing the data of the current node
        cout << temp->data << " ";
        // moving the temp pointer to the next node of the linkedlist
        temp = temp->next;
    }
    // Once we are here it means we have printed all the nodes of the linkedlist on the console
    cout << endl;
}