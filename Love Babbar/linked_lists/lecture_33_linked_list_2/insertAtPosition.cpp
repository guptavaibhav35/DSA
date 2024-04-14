#include <iostream>
#include "Node.h"
#include "insertAtPosition.h"
#include "findLength.h"
using namespace std;

//**************************************************************************
//**Insertion at a position of the linkedlist*
//**************************************************************************
// The main task here is to insert data into a new node in the linkedlist at a specific position in the linkedlist
// This function has a void return type and takes in 4 parameters which are: head of the linkedlist, tail of the linkedlist,
// data that has to be inserted in the new node and the position at which the new node has to be inserted.
// The main idea behind this also is to first check is this is our first node in the linkedlist or not as the user may specify
// any position but if that position does not exist then it makes no sense to insert the node at that place hence we are first checking
// if this is our first node in the linkedlist or not, for that we will check if the head and tail of the linkedlist is equal to
// NULL or not?, if yes then it means that it is our first node in the linkedlist
// So we will create our first node and also assign its data element, and since this is our first node in the linkedlist
// so the head and the tail pointer must point to this node.
// else if false we will check if the value of position is equal to 1 or not?, if yes then it means we have to insert at
// the head of the linkedlist, so in that we will first create a new node temp and also assign it its data element
// then we will make the next of this temp node point to the current head of the linkedlist
// and we will make the prev of the current head point to this current node
// then we will make the head of the linkedlist point to this new node temp
// else if false, we will then check if the position to insert the node is greater than or equal the lenght of the linkedlist
// So for that we will be using the findLength() to check the lenght of the linkedlist
// or not, if yes then it means that we need to insert the new node at the tail of the linkedlist
// So we will create a new node temp and also initialize the data element for it
// Then we will make the next of the tail point to this new node temp
// then we will make the prev of this new node temp point to the current tail of the linkedlist
// then we will make the tail point to the new node temp of the linkedlist
// Else if false, then it means that the position to insert our new node is in the middle of the linkedlist
// so first we will try to reach the node before the position where we have to insert the new node in the linkedlist
// so for that we will use a variable pos that will help us to store the current position of the linkedlist
// also we will create a new Node pointer temp which will be equal to the current head of the linkedlist and will act as our head
// then we will use our while loop to iterate over the linkedlist where the breakout condition will be the check if the temp is equal to null or not and
// if the current position is one position behind the position where we need to insert our new node. Until then we will keep moving the temp pointer ahead
// and also keep updating the current position.
// Once we are at the position where we need to insert our node, we create a new node and assign the data element to that node. Now we have created a new node
// so we will make the next of this new node point to the next of the current node. Then we will make the prev of new node point to the current node.
// Then we will make the prev of new node next node point to the new node and then make the next of the current node point to the new node. This way we managed to
// place a new node at the given position in a doubly linkedlist.
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    // Creating a variable length that will help us get the length of the linkedlist which will be returned by the findLength() function which takes in head of the
    // linkedlist as the parameter.
    int length = findLength(head);
    // Then we will check if the linkedlist is empty or not and the new node that we will be creating will be our first node or not?
    // So for that we are checking if the head and tail of the linkedlist are pointing to null or not
    if (head == NULL && tail == NULL)
    {
        // If yes then this is our first node in the linkedlist
        // Hence creating a new node and assigning its data element
        Node *temp = new Node(data);
        // Since this is our first node so the head and the tail of the linkedlist will point to this new node.
        tail = temp;
        head = temp;
    }
    // If not then the linkedlist already has some nodes.
    // Then we will check if the user wants us to insert the new node at the first position or not?
    else if (position == 1)
    {
        // If yes then the user wants us to insert the node at the head of the linkedlist
        // So creating a new node and assigning its data element
        Node *temp = new Node(data);
        // Then making the next pointer of the new node point to the head of the linkedlist
        temp->next = head;
        // Also making the prev of the current head point to the new node
        head->prev = temp;
        // Then making the current head of the linkedlist point to this new node as this will be our new head
        head = temp;
    }
    // If not then we need to check if the user has entered a valid position or not?
    // So in a valid position we are checking if the position entered by the user is greater than the length of the linkedlist or not?
    else if (position >= length)
    {
        // If yes then the user wants us to insert the new node at the tail of the linkedlist
        // So creating a new node and assigning its data element
        Node *temp = new Node(data);
        // Then making the next of the tail pointer point to the new node temp
        tail->next = temp;
        // Then making the prev of the new node temp point to the current tail of the linkedlist
        temp->prev = tail;
        // Now since this new node will be our new tail, so making the tail point to this new node.
        tail = temp;
    }
    // If not then it means that the user wants us to insert a new node somewhere middle in the linkedlist
    else
    {
        // So creating a variable pos that will help us to keep a track of the current position in the linkedlist
        int pos = 1;
        // Now creating a temp pointer that will act as the iterator to traverse thru the linkedlist
        Node *temp = head;
        // Using a while loop to traverse thru the linkedlist where the breakout condition is to check if the next current pointer is not equal to null (just for safety)
        //  and the main condition is to see that the current position is not more than userposition - 1
        while (temp != NULL && pos < position - 1)
        {
            // If yes then moving the temp pointer one step forward
            temp = temp->next;
            // Incrementing the pos value by 1 as we are moving forward
            pos++;
        }
        // Now we are the the position where on the right we need to insert our new node
        // So making a new node and also assigning the data element to it
        Node *newNode = new Node(data);
        // Then making the next of the new node point to the next of the current node.
        newNode->next = temp->next;
        // then making the prev of the new node point to the current node
        newNode->prev = temp;
        // then making the prev of the new node next node point to the new node
        newNode->next->prev = newNode;
        // Finally making the next of the current node point to the new node
        temp->next = newNode;
    }
}