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

    // creating the push() function to implement the push functionality in the queue
    // this function ahs a void return type and takes in the data that has to be inserted
    // in the queue
    void push(int data)
    {
        // First checking if the queue is full or not
        // Since we are using a 0 based indexing here so we are updating the value of rear after pushing
        // the element in the queue
        // So the rear index always stores the index of an empty box if the queue is empty
        // for that we are checking if the size of the queue and the rear index are equal or not?
        if (rear == size)
        {
            // If yes then printing it on the console
            cout << "OVERFLOW: the queue is full, Cannot push element" << endl;
            // Returning back to the function call
            return;
        }

        // Now we are checking if the front and rear of the queue is equal to 0 or not?
        // This means that the queue is empty
        if (front == 0 && rear == 0)
        {
            // If yes then we insert the element at the front or rear index
            arr[front] = data;
            // then we only increment the rear index as rear index has to store the index of the next empty space
            // in the queue until the empty is full
            rear++;
            // Printing the confirmation message on the console
            cout << "Success: Element has been pushed in the queue" << endl;
            // Returning back to the function call
            return;
        }

        // If none of the above conditions are true then it means queue has some elements and is neither empty
        // nor full.
        // So we insert the data at the rear index of the queue
        arr[rear] = data;
        // Then increment the value of queue as it has to store the index of the next avaibale space in the queue
        rear++;
        // Printing the confirmation message on the console
        cout << "Success: Element has been pushed in the queue" << endl;
        // returning back tot he function call
        return;
    }

    // Implementing the pop functionality of the queue using the pop() function
    // this function has a void return type and does not take any arguments
    void pop()
    {
        // So the first step to check if the queue is empty or not?
        // For that we check if the rear and front are equal or not?
        // It happend only when the queue is empty as both of them will be at 0 index
        if (rear == front)
        {
            // If yes then we print the error message on the console
            cout << "UNDERFLOW: Cannot pop element, queue is empty" << endl;
            // returning back to the function call
            return;
        }

        // If not then it means that the queue is not empty
        // So we make the value of front index in the queue as INT_MIN
        arr[front] = INT_MIN;
        // Then we increment the value of front so that it points to the next element in the queue
        front++;

        // Now we check if after popping the queue has become empty or not?
        // We are doing it again by checking if the front and rear are equal or not?
        if (front == rear)
        {
            // If yes then we will make them point to the 0th index to save space
            front = 0;
            rear = 0;
        }
        // Printing the success message on the console
        cout << "SUCCESS: Element popped from the queue" << endl;
        // Retuning back to the function call
        return;
    }

    // This function here is to implement the functionality of getting the front element of the queue
    // It has an integer return type as it returns the value of the front most element in the queue
    // It has no arguments
    int getFront()
    {
        // It first checks if the queue is empty or not
        // for that we are checking if the rear and front index are same or not?
        // Since they are only empty when the queue is empty
        if (rear == front)
        {
            // If yes then we are prinitng the error message on the console
            cout << "UNDERFLOW: Cannot retrieve the front element, queue is empty" << endl;
            // Also returning INT_MIN value back to the function call
            return INT_MIN;
        }
        // If here then it means that the queue is not empty and it has some elements
        // hence we are returning the value of the frontmost element in the queue
        return arr[front];
    }

    // The function here is to implement the functionality of getting the rear element of the queue
    // It has an integer return type as it returns the value of the rear most element in the queue
    // It has no arguments
    int getRear()
    {
        // It first checks if the queue is empty or not?
        // SO for that we are checking if the rear and front index are same or not
        // as they are only same when the queue is empty
        if (rear == front)
        {
            // So if the queue is empty then we are printing the error message on the console
            cout << "UNDERFLOW: Cannot retrieve the rear element, queue is empty" << endl;
            // Also returning INT_MIN value back to the function call
            return INT_MIN;
        }
        // If here then it means that the queue is not empty and it has some elements
        // hence we are returning the value of the rearmost element in the queue
        // And since the rear points to an empty location in the queue because it a 0 based indexing
        // hence we are returning the element at rear-1 index.
        return arr[rear - 1];
    }

    // This function here is to implement the functionality of getting the number of elements in the
    // queue or the size of the queue
    // It has an integer return type that returns the value of the number of elements in the queue
    // It has no arguments
    int getSize()
    {
        // So here the trick to calculate the number of elements in the queue is to subtract the value
        // of front index from the rear index as they are 0 based indexing and not -1 based indexing
        // and then return this value
        return rear - front;
    }

    // This function is implementing the functionality of checking if the queue is empty or not?
    // It has a bool return type which return a true value if the queue is empty and a false value
    // if the queue is not empty and has some elements in it
    bool isEmpty()
    {
        // Checking if the queue is empty is simple, we are just comparing the values of the rear and
        // the front index, they are only equal if the queue is empty
        if (front == rear)
        {
            // If here then it means that the front and rear index are equal and the queue is empty
            // hence returning a true value
            return true;
        }
        // If here then it means that the front and rear index are not equal and the queue has some value
        else
        {
            // If here then it means that the queue is not empty as front and rear index are not equal
            // hence returning false
            return false;
        }
    }

    // The function here implements the functionality of checking the available space in the queue
    // It has not arguments and an integer return type which returns the space for number of elements
    // that can be pushed
    int findSpaceAvailableQueue()
    {
        // So here the calculation is pretty straightforward, we are calculating it by subtracting
        // the number of elements present in the queue from the total size of the queue
        // So total_size-(rear-front) = size-rear-front. then returning this value
        return size - rear + front;
    }
};

//**************************************************************************
//**Implementing Queue wwithout using STL**
//**************************************************************************
// Here we are trying to implement a queue using the our own class
// This function has a void return type and does not take any arguments
// The main idea here is to implement these functionalities: push an element in the queue, pop, size, empty, back and front
void queue_without_stl()
{
    cout << "**************************************************************************" << endl;
    cout << "**Implementing Queue without using STL**" << endl;
    cout << "**************************************************************************" << endl;

    // Creating the object of our class Queue. The size of queue is 10.
    Queue q(10);
    // using the push() function to push elements in the queue
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
    // using the getFront() function to get the frontmost element of the queue
    int front = q.getFront();
    // Checking is the queue is empty or not by checking the value returned, if its INT_MIN, queue is empty
    if (front != INT_MIN)
    {
        // it means that the queue is not empty and hence priniting it on the console
        cout << "The frontmost element in the queue is " << front << endl;
    }
    // Using the getRear() function to get the rearmost element of the queue
    int rear = q.getRear();
    // Checking if the queue is empty or not by checking the value returned, if its INT_MIN, queue is empty
    if (rear != INT_MIN)
    {
        // If here then it means that the queue is not empty and hence priniting it on the console
        cout << "The rearmost element in the queue is " << rear << endl;
    }
    // Using the getSize() function to get the size of the queue and printing it on the console
    cout << "The size of the queue is " << q.getSize() << endl;
    // Using the isEmpty() function to check if the queue is empty or not?
    if (q.isEmpty())
    {
        // If here then it means that the queue is empty and priniting it on the console
        cout << "Queue is empty" << endl;
    }
    // If here then it means that the queue is not empty
    else
    {
        // If here then it means that the queue is not empty and hence prinitng the size of the queue by using the getSize() function
        cout << "The given queue is not empty and has: " << q.getSize() << " elements." << endl;
    }
    // Using the findSpaceAvailableQueue() function to check the space available in the queue and printing it
    cout << "Space available in the queue is " << q.findSpaceAvailableQueue() << endl;
    // Using the pop() function to pop the element of the queue from its front
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
    // using the getFront() function to get the frontmost element of the queue
    front = q.getFront();
    // Checking is the queue is empty or not by checking the value returned, if its INT_MIN, queue is empty
    if (front != INT_MIN)
    {
        // it means that the queue is not empty and hence priniting it on the console
        cout << "The frontmost element in the queue is " << front << endl;
    }
    // Using the getRear() function to get the rearmost element of the queue
    rear = q.getRear();
    // Checking if the queue is empty or not by checking the value returned, if its INT_MIN, queue is empty
    if (rear != INT_MIN)
    {
        // If here then it means that the queue is not empty and hence priniting it on the console
        cout << "The rearmost element in the queue is " << rear << endl;
    }
    // Using the getSize() function to get the size of the queue and printing it on the console
    cout << "The size of the queue is " << q.getSize() << endl;
    // Using the isEmpty() function to check if the queue is empty or not?
    if (q.isEmpty())
    {
        // If here then it means that the queue is empty and priniting it on the console
        cout << "Queue is empty" << endl;
    }
    // If here then it means that the queue is not empty
    else
    {
        // If here then it means that the queue is not empty and hence prinitng the size of the queue by using the getSize() function
        cout << "The given queue is not empty and has: " << q.getSize() << " elements." << endl;
    }
    // Using the findSpaceAvailableQueue() function to check the space available in the queue and printing it
    cout << "Space available in the queue is " << q.findSpaceAvailableQueue() << endl;
}