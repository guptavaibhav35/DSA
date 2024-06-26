#include <iostream>
#include "queue_stl.cpp"
#include "queue_without_stl.cpp"
#include "circular_queue.cpp"
using namespace std;

int main()
{
    //**************************************************************************
    //*Queue 1*
    //**************************************************************************

    // here we are trying to use the built in or STL queue library to implement queue and
    // also perform operations on it
    // Calling the queue_stl() to implement it
    queue_stl();

    // here we are trying to build our own class for queue and also implementing all functions
    // for operations on the queue
    // calling the queue_without_stl() to implement it
    queue_without_stl();

    // Here we are trying to build our own class for circular queue and also implementing all
    // functions for operations on the queue
    // Calling the circular_queue() function to implement it
    circular_queue();
    return 0;
}