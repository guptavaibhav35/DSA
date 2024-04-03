#include <iostream>

//**************************************************************************
//**Implementing Queue using our own class**
//**************************************************************************
// here the task is to implement our own class to develop a queue
class Queue
{
    // Public data members and functions of the queue
public:
    // Size of the queue
    int size;
    // Front index of the queu
    int front;
    // Rear index of the queue
    int rear;
    // Using an array to implement our queue
    int *arr;

    // Constructor for our class queue, taking the size of the queue to be implemented
    // as an argument
    Queue(int size)
    {
        // Assigning the value of size to the public data member size
        this->size = size;
        // Assigning the value 0 to our queue's front index since our queue is empty right now
        front = 0;
        // Assigning the value 0 to our queues rear index since our queue is empty right now
        rear = 0;
        // Initializing our queue of the size passed as an argument
        arr = new int[size];
    }

    //
    void push(int data)
    {
        if (rear == size)
        {
            cout << "OVERFLOW: the queue is full, Cannot push element" << endl;
            return;
        }

        if (front == 0 && rear == 0)
        {
            arr[front] = data;
            rear++;
            cout << "Success: Element has been pushed in the queue" << endl;
            return;
        }

        arr[rear] = data;
        rear++;
        cout << "Success: Element has been pushed in the queue" << endl;
        return;
    }

    void pop()
    {
        if (rear == front)
        {
            cout << "UNDERFLOW: Cannot pop element, queue is empty" << endl;
            return;
        }

        arr[front] = INT_MIN;
        front++;
        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        cout << "SUCCESS: Element popped from the queue" << endl;
        return;
    }

    int getFront()
    {
        if (rear == front)
        {
            cout << "UNDERFLOW: Cannot retrieve the front element, queue is empty" << endl;
            return INT_MIN;
        }

        return arr[front];
    }

    int getRear()
    {
        if (rear == front)
        {
            cout << "UNDERFLOW: Cannot retrieve the rear element, queue is empty" << endl;
            return INT_MIN;
        }

        return arr[rear - 1];
    }

    int getSize()
    {
        return rear - front;
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int findSpaceAvailableQueue()
    {
        return size - rear + front;
    }
};

void queue_without_stl()
{
    Queue q(10);
    q.push(10);
    q.push(10);
    q.push(10);
    q.push(10);
    q.push(10);
    q.push(10);
    q.push(10);
    q.push(10);
    q.push(10);
    q.push(100);
    q.push(100);
    int front = q.getFront();
    if (front != INT_MIN)
    {
        cout << "The frontmost element in the queue is " << front << endl;
    }
    int rear = q.getRear();
    if (rear != INT_MIN)
    {
        cout << "The rearmost element in the queue is " << rear << endl;
    }
    cout << "The size of the queue is " << q.getSize() << endl;
    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "The given queue is not empty and has: " << q.getSize() << " elements." << endl;
    }
    cout << "Space available in the queue is " << q.findSpaceAvailableQueue() << endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    front = q.getFront();
    if (front != INT_MIN)
    {
        cout << "The frontmost element in the queue is " << front << endl;
    }
    rear = q.getRear();
    if (rear != INT_MIN)
    {
        cout << "The rearmost element in the queue is " << rear << endl;
    }
    cout << "The size of the queue is " << q.getSize() << endl;
    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "The given queue is not empty and has: " << q.getSize() << " elements." << endl;
    }
    cout << "Space available in the queue is " << q.findSpaceAvailableQueue() << endl;
}