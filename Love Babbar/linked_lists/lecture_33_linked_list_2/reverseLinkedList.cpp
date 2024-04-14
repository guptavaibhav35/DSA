#include <iostream>
#include "Node.h"
#include "reverseLinkedList.h"
using namespace std;

//**************************************************************************
//**Reversing a linkedlist**
//**************************************************************************
// The main task here is to reverse a linkedlist.
// This function is using a void return type and takes in 3 parameters. The first parameter is the head of the linkedlist,
// the second parameter is the current pointer in the linkedlist. So this parameter behaves like the iterator for traversing
// our linkedlist. The next parameter is the left pointer of the linkedlist which point to the node before the current node.
// So in the first call the current will be the head of the linkedlist and the left will be null.
// The main intuition here is to use recursion to reverse our linkedlist. Since we are using recursion our base condition will be
// to check if the current pointer of the linkedlist is NULL or not, If yes then it means we have traversed the linkedlist completely
// and all the nodes have been reveresed and we are at the end of the linkedlist
// IF the base condition is hit then the left pointer will be pointing to the last node of the linkedlist, last in the sense
// to the rightmost node of the linkedlist. This last pointer will be our new head, so when the base condition is hit
// we make the head of the linkedlist point to this left pointer and then return back
// If the base condition is not hit then it means there are still some nodes left to reverse.
// So the intuition to reverse a linkedlist is simple, we first make a right pointer that point to the node on the right of the current node.
// This is done so as to not loose track of nodes on the right of the current node.
// Then in order to reverse it we make the next pointer of the current node point to the node on the left of the current node.
// Then we make the left pointer point to the current node and then we make the current pointer point to the node pointerd by the right pointer.
// Then we recursively call the function with head, current and left as the parameters
void reverseLinkedList(Node *&head, Node *curr, Node *left)
{
    // Base condition where we are checking if the current pointer is NULL or not
    if (curr == NULL)
    {
        // If yes then it means we have reached the end of the linkedlist and all the nodes have been reversed.
        // So the left pointer will be pointing to the rightmost node of the linkedlist and can be our new head
        // so we make the head point to the left node of the linkedlist
        head = left;
        // Then return back to the function call
        return;
    }

    // If here then it means there are still nodes left to be reversed
    // So we first make a right pointer point to the node on the right of the current node, this is done to not loose track of the nodes on the right of
    // the current node in the linkedlist
    Node *right = curr->next;
    // Then we make the next of the current node point to the left node
    curr->next = left;
    // Then we make the left node point to the current node
    left = curr;
    // then we make the current node point to the right node
    curr = right;
    // Then we recursively call the function with head, current and left pointers as parameters.
    reverseLinkedList(head, curr, left);
}