#include <iostream>
#include "Node.h"
#include "findLength.h"
#include "deleteNode.h"
using namespace std;

//**************************************************************************
//**Delete a node from the linkedlist*
//**************************************************************************
// so the main task here is to delete a node at a specific position from the linkedlist.
// This function has a void return type and takes in 3 parameters which are : the head, tail of the linkedlist and also the user specified position
// from where we need to delete the node from the linkedlist
// The main intuition here is to first create a temp pointer which will act as our head of the linkedlist and will help us to iterate over the linkedlist
// Then the next step is to check if the linkedlist is empty or not. for that we will check if the head of the linkedlist is equal to NULL or not?
// If yes then the linkedlist is empty and we cannot delete any node from it so we return back to the function
// Next we check if the position given by the user is equal to 1 or not?
// If yes then we have to delete the head of the linkedlist
// If yes then we check if the length of the linkedlist is also one or not? For that we will use the findLength() function which returns the lenght of the linkedlist
// If yes then this is the only node in the linkedlist and we have to delete it
// So for that we will first make the head and tail of the linkedlist point to null, then we will make the next and prev of this temp node point to null
// Then we will call the deletenode destructor of the class node to delete the node and then return back to the function
// But if the length og the linkedlist is not 1 then it means we have to delete the first node in the linkedlist
// So for that we will first move the head pointer to the next node and then make the next pointer of the temp node point to null
// Then we will make the prev of head node point to null then we will make the prev of temp node point to null and then we will make the next of
// temp node point to null, then we will call the deletenode destructor of the class node and return back to the function call
// If the position given by the user is not one then we check is its equal to the length of the linkedlist or not?
// If yes then it means we have to delete the tail node of the linkedlist
// so for that we first make a temp pointer that will be the tail fo the linkedlist
// Then we will make the next of this temp pointer point to null
// then we will make the tail of the linkedlist move one step backward by making tail equal to tail's prev pointer
// then we will make the next of tail point to null
// then we will make the prev pointer of the temp node point to nullptr
// then we will call the destructor to delete the node
// then return back to the function call
// Else if the poistion given by the user is less than the length of the linkedlist then it means that we need to delete a node from the middle of the linkedlist
// so for that we need to iterate to one node before the position from where we need to delete the node
// so we create a variable i that will be the iterator to traverse the linkedlist
// so for that we are using a while loop to traverse the linkedlist where the breakout condition is to see if the value of i is less than position-1 or not
// if yes the we make the temp_head pointer move to the next node and we also increment the value of variable i
// now we are at one node to the left of the node which has to be deleted
// Then we make a temp pointer that will point to the next of the temp_head. so temp pointer is pointing to the node that has to be deleted
// so we first make the next of temp_head point to next of temp node.
// then we make the prev of temp next node point to temp_head
// then we make the prev of temp and next of temp point to null
// then call the destructor to delete the node
// then return back
// else it means that the position entered by the user is not a valid position.
void deleteNode(Node *&head, Node *&tail, int position)
{
  // Initialize temp_head to act as a current pointer starting from head
  Node *temp_head = head;

  // Check if list is empty; if so, there is nothing to delete
  if (head == NULL)
  {
    return; // Exit the function as there's nothing to do
  }

  // Check if the node to delete is the first one
  if (position == 1)
  {
    // Call findLength to determine the size of the list
    int length = findLength(head);
    // Check if there's only one node in the list
    if (length == 1)
    {
      // Set both head and tail to NULL as the list will be empty after deletion
      head = NULL;
      tail = NULL;
      // Disconnect the to-be-deleted node from the list
      temp_head->next = NULL;
      temp_head->prev = NULL;
      // Delete the only node in the list
      delete temp_head;
      return; // Node deleted; exit the function
    }
    else
    {
      // Update the head to the next node since the first node will be deleted
      head = head->next;
      // Disconnect the to-be-deleted node from the list
      temp_head->prev = NULL;
      // Previously this node was the head, so its prev was already NULL
      head->prev = NULL;
      // Disconnect the node from its next node
      temp_head->next = NULL;
      // Delete the node which was the original head
      delete temp_head;
      return; // Node deleted; exit the function
    }
  }
  // Check if the node to delete is the last one
  else if (position == findLength(head))
  {
    // Use a temporary pointer to the tail for deletion
    Node *temp = tail;
    // Disconnect the last node from the list
    temp->next = NULL;
    // Update the tail to the second-last node
    tail = tail->prev;
    // Set the new tail's next to NULL
    tail->next = NULL;
    // Disconnect the deleted node's prev pointer
    temp->prev = NULL;
    // Delete the node
    delete temp;
    return; // Node deleted; exit the function
  }
  // Check if the node to delete is in between the first and the last
  else if (position < findLength(head))
  {
    // Iterate through the list up to the node before the one to delete
    int i = 1;
    while (i < position - 1)
    {
      // Traverse the list
      temp_head = temp_head->next;
      i++;
    }
    // Use temp to point to the node to be deleted
    Node *temp = temp_head->next;
    // Link the previous node with the next node, skipping over temp
    temp_head->next = temp->next;
    // Link next node's previous pointer back to temp_head
    temp->next->prev = temp_head;
    // Disconnect the deleted node's prev and next pointers
    temp->prev = NULL;
    temp->next = NULL;
    // Delete the node that was at the given position
    delete temp;
    return; // Node deleted; exit the function
  }
  // If an invalid deletion position beyond the list bounds is specified
  else
  {
    // Output an error message
    cout << "Invalid Position" << endl;
  }
}