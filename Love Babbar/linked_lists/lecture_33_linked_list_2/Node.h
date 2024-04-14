// utilities.h
#ifndef NODE_H
#define NODE_H

// Any other related declarations, such as constants, classes, or enums, can go here too
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node();
    Node(int val);
    ~Node();
};
#endif
