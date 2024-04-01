#include <iostream>
using namespace std;

// Initializing a class Node to create a double linkedlist
// This is a double linkedlist so it will have 3 data members: data, next pointer and previous pointer.
class Node
{
  // Creating the public data members of the class Node.
public:
  // The data for the node of the linkedlist
  int data;
  // The next pointer of the node of the linkedlist
  Node *next;
  // The previous pointer of the node of the linkedlist
  Node *prev;

  // Constructor for this class node, this is the default constructor that will be called
  // whenever a new object of the class Node is created.
  // Since this is the default constructor, this will help us to initialize the
  // Data members of the class Node with some default values
  Node()
  {
    // Setting the value of data of the object to 0
    this->data = 0;
    // Setting the next pointer of the object to NULL
    this->next = NULL;
    // Setting the previous pointer of the object to NULL
    this->prev = NULL;
  }

  // This is another constructor in which we are getting an argument which is the
  // data for the object or node in this case
  // So here we will be setting the data of this object or node in this case to
  // the value of this argument and will set the next and previous pointer to NULL
  Node(int val)
  {
    // Setting the data of this object equal to val
    this->data = val;
    // Setting the next pointer of the object to NULL
    this->next = NULL;
    // Setting the prev pointer of the object to NULL
    this->prev = NULL;
  }

  // This is the destructor for this class
  // This will be called whenever we want to delete the object of this class
  // It will delete that object and will also print a message that the object
  // or node in this case has been deleted
  ~Node()
  {
    // Displaying the message that the node has been deleted.
    cout << "Node is deleted" << endl;
  }
};

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

  cout << "Priniting the doubly linkedlist: " << endl;
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

void insertAtTail(Node *&head, Node *&tail, int data)
{
  if (head == NULL && tail == NULL)
  {
    Node *temp = new Node(data);
    tail = temp;
    head = temp;
  }
  else
  {
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
  if (head == NULL && tail == NULL)
  {
    Node *temp = new Node(data);
    tail = temp;
    head = temp;
    return;
  }
  else
  {
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
    return;
  }
}

void insertAtPosition(Node *&head, Node *tail, int data, int position)
{

  if (head == NULL && tail == NULL)
  {
    Node *temp = new Node(data);
    tail = temp;
    head = temp;
  }
  else if (position == 1)
  {
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
  else
  {
    int pos = 1;
    Node *temp = head;
    while (pos < position - 1)
    {
      temp = temp->next;
      pos++;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    newNode->next->prev = newNode;
    temp->next = newNode;
  }
}

int findLength(Node *head)
{
  Node *temp = head;
  int len = 0;
  if (temp == NULL)
  {
    return len;
  }
  if (temp != NULL)
  {
    len++;
  }
  while (temp->next != NULL)
  {
    len++;
    temp = temp->next;
  }
  return len;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
  Node *temp_head = head;

  if (head == NULL)
  {
    return;
  }

  if (position == 1)
  {
    int length = findLength(head);
    if (length == 1)
    {
      head = NULL;
      tail = NULL;
      temp_head->next = NULL;
      temp_head->prev = NULL;
      delete temp_head;
      return;
    }
    else
    {
      head = head->next;
      temp_head->prev = NULL;
      head->prev = NULL;
      temp_head->next = NULL;
      delete temp_head;
      return;
    }
  }
  else if (position == findLength(head))
  {
    Node *temp = tail;
    temp->next = NULL;
    tail = tail->prev;
    tail->next = NULL;
    temp->prev = NULL;
    delete temp;
    return;
  }
  else if (position < findLength(head))
  {
    int i = 1;
    while (i < position - 1)
    {
      temp_head = temp_head->next;
      i++;
    }
    Node *temp = temp_head->next;
    temp_head->next = temp->next;
    temp->next->prev = temp_head;
    temp->prev = NULL;
    temp->next = NULL;
    delete temp;
  }
  else
  {
    cout << "Invalid Position" << endl;
  }
}

void reverseLinkedList(Node *&head, Node *curr, Node *left)
{
  if (curr == NULL)
  {
    head = left;
    return;
  }

  Node *right = curr->next;
  curr->next = left;
  left = curr;
  curr = right;

  reverseLinkedList(head, curr, left);
}

int create_and_print_doubly_linked_list()
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

  insertAtPosition(head, tail, 2012, 3);
  printList(head);
  deleteNode(head, tail, 9);
  printList(head);
  reverseLinkedList(head, head, NULL);
  printList(head);

  //****

  return 0;
}