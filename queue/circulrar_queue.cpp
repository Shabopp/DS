#include <iostream>
#include <bits/stdc++.h> 

class CircularQueue{

    int *arr;

    int size;

    int rear,front;

    public:

    // Initialize your data structure.

    CircularQueue(int n){

        size=n;

        arr=new int[size];

        front=rear=-1;

    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.

    bool enqueue(int data){

        // Write your code here.

        if((front==0 && rear==size-1) || (rear==front-1)) {

            return 0;

        }

        else if(front==-1) {

            front=rear=0;

        }

        else if(rear==size-1 && front!=0) {

            rear = 0;

        }

        else {

            rear++;

        }

        arr[rear]=data;

        return true;

    }

 

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.

    int dequeue(){

        if(front==-1) {

            return -1;

        }

        int ele=arr[front];

        if(front==rear) {

            front=rear=-1;

        }

        else if(front==size-1) {

            front=0;

        }

        else {

            front++;

        }

        return ele;

 

    }

};

int main() {
    // Create a CircularQueue with a capacity of 5
    CircularQueue queue(5);

    // Enqueue elements into the queue
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    // Attempt to enqueue another element (should return false as the queue is full)
    if (queue.enqueue(6)) {
        std::cout << "Enqueue successful" << std::endl;
    } else {
        std::cout << "Enqueue failed (Queue is full)" << std::endl;
    }

    // Dequeue elements from the queue
    int dequeuedValue1 = queue.dequeue();
    int dequeuedValue2 = queue.dequeue();
    int dequeuedValue3 = queue.dequeue();

    // Enqueue more elements
    queue.enqueue(6);
    queue.enqueue(7);

    // Dequeue the remaining elements
    int dequeuedValue4 = queue.dequeue();
    int dequeuedValue5 = queue.dequeue();

    // Attempt to dequeue another element (should return -1 as the queue is empty)
    int dequeuedValue6 = queue.dequeue();

    // Display the dequeued values
    std::cout << "Dequeued Values: " << dequeuedValue1 << " " << dequeuedValue2 << " " << dequeuedValue3 << " " << dequeuedValue4 << " " << dequeuedValue5 << " " << dequeuedValue6 << std::endl;

    return 0;
}
