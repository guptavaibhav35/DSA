#include <iostream>
#include <queue>

using namespace std;

//**************************************************************************
//**Implementing Queue using STL**
//**************************************************************************
// Here we are trying to implement a queue using the standard template library
// This function has a void return type and does not take any arguments
// The main idea here is to push an element in the queue using the stl functions, other operations
// also included in this function are : pop, size, empty, back and front
void queue_stl()
{
    // Initializing a queue using stl
    queue<int> q;
    // Pushing elements in the queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    // checking the current size or the number of elements in the queue, for this we are uisng the
    // stl function size(), it returns the number of elements present in the queue.
    cout << "The current size of the queue is: " << q.size() << endl;
    // Popping elements from the queue
    q.pop();
    // checking the current size or the number of elements in the queue, for this we are uisng the
    // stl function size(), it returns the number of elements present in the queue.
    cout << "The current size of the queue is: " << q.size() << endl;
    // checking if the queue is empty or not using the stl function empty(), it returns a bool value
    // of true if the queue is empty else a false value if the queue is not empty
    if (q.empty())
    {
        // If true then it means the queue is empty
        // Printing the message on the console
        cout << "The given queue is empty." << endl;
    }
    // If here then it means that the queue is not empty and it has some elements
    else
    {
        // Printing the message on the console and additionally printing the number of elements
        // present in the queue
        cout << "The given queue is not empty and has: " << q.size() << " elements." << endl;
    }
    // Printing the frontmost element of the queue using the stl function front()
    // it returns the value of the element at the front of the queue
    cout << "The frontmost element of the queue is " << q.front() << endl;
    // Printing the rearmost element of the queue using the stl function rear()
    // it returns the value of element at the rear of the queue
    cout << "The rearmost element of the queue is " << q.back() << endl;
}