#include <iostream>
#include "Node.h"
#include "findLength.h"
using namespace std;

//**************************************************************************
//**Finding length of the linkedlist*
//**************************************************************************
// The main task here is to find the number of nodes in the linkedlist or the length of the linkedlist
// This function has an int return type as it returns the count of nodes in the linkedlist, also it only has one parameter which is the
// head of the linkedlist
// So the main idea here is to first create a Node type pointer temp and make it point to the current head of the linkedlist,
// so here this temp pointer will behave as our new head of the linkedlist
// Now we will create a variable len with an intial value of 0, this variable will store the count of the number of nodes of the linkedlist
// first we will check if the temp pointer is pointing to NULL or not,
// if true then it means that the head is pointing to NULL and the linkedlist is empty as it has no nodes
// so in that condition we willr return the variable len which in this case has a value 0
// else if the temp is not pointing to NULL, then it means there is atlease one node in the linkedlist,
// so we will increment the variable len by 1
// then we will use a while loop to iterate over our linkedlist, so the breakout condition here will be to check if the next of the temp is equal to null or not?
// if no then it means there are some nodes ahead of the current pointer temp,
// so we will increment the value of len variable by 1 and then move our temp pointer to the next node.
// At last we return the len variable which has the count of number of nodes in our linkedlist
int findLength(Node *head)
{
    // Creating a temp pointer that points to the current head of the linkedlist
    Node *temp = head;
    // Creating a len variable and initializing it with a value 0 which will help us to store the count of number of nodes
    int len = 0;
    // now checking if the linkedlist is empty or not, so for that we will check if the temp pointer points to NULL or not?
    if (temp == NULL)
    {
        // If yes then our linkedlist is empty and we return back to the functionc all, the len variable which has a value of 0.
        return len;
    }
    // If not then it means we might have a node in the linkedlist
    if (temp != NULL)
    {
        // So if the temp is not equal to NULL then it means we have atleast one node in the linkedlist
        // Incrementing the value of len by 1
        len++;
    }

    // Now using a while loop to iterate over the linkedlist where the breakout condition will be
    while (temp->next != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}