#include <iostream>
#include "Node.h"
#include "insertInCircular.h"

//**************************************************************************
//**Finding length of the linkedlist*
//**************************************************************************
// The main task here is to insert a new node in a circular linkedlist.
// This function has a void return type as it does not returns anything and takes 2 parameters which are the head of the
// linkedlist and the data that has to be inserted in the linkedlist
// The main idea here is to first find the position in the linkedlist where this new node can be inserted
// Now since this is a circular linkedlist we do not have the head and the tail of the linkedlist
// So the first task is to create a temp pointer which will act as our new head of the linkedlist and will
// help us to traverse over the linkedlist
// Then we check if the linkedlist is empty or not? for that we check if the temp pointer is equal to NULL or not?
// if yes then our linkedlist does not have any node in the lindkedlist and this new node will be our first node
// so we go ahead and create that new node and assign it the data that was passed in the parameters of the function call.
// then we make this new node as the head of the linkedlist, for that we make the head pointer point to this new node
// now since this is a circular linkedlist, we will have to make connections for the prev and the next pointer as they cannot be null
// So we make the prev and next of this new node point to itself or the head of the linkedlist
// but if the temp pointer is not null which means that the linkedlist already has some nodes in it
// then we need to go and find the place where we can insert the new node in the linkedlist
// so for that we will be using the temp pointer we initialized in the start of this function