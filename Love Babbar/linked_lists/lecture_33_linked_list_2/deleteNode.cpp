#include <iostream>
#include "Node.h"
#include "findLength.h"
#include "deleteNode.h"
using namespace std;

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
