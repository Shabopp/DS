#include <iostream>
class Queue {
    
    int* arr;
    int qfront;
    int rear; 
    int size;
    
public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear) {
            return true;
        }
        else
        {
            return false;
        }
    }

  void enqueue(int data) {
    if (rear == size) {
        std::cout << "Queue is Full" << std::endl;
        return; // Return early when the queue is full
    } else {
        arr[rear] = data;
        rear++;
    }
}


    int dequeue() {
        if(qfront == rear) {
            return -1;
        }
        else
        {	int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront==rear){
                qfront = 0;
                rear = 0;
            }
         return ans;
        }
    }

    int front() {
        if(qfront == rear) {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};

int main() {
    Queue queue;

    // Enqueue elements into the queue
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    // Dequeue elements from the queue
    int dequeuedValue1 = queue.dequeue();
    int dequeuedValue2 = queue.dequeue();
    int dequeuedValue3 = queue.dequeue();

    // Get the front element of the queue
    int frontValue = queue.front();

    // Enqueue more elements
    queue.enqueue(6);
    queue.enqueue(7);

    // Dequeue the remaining elements
    int dequeuedValue4 = queue.dequeue();
    int dequeuedValue5 = queue.dequeue();
    int dequeuedValue6 = queue.dequeue();

    // Check if the queue is empty
    bool isEmpty = queue.isEmpty();

    // Display the results
    std::cout << "Dequeued Values: " << dequeuedValue1 << " " << dequeuedValue2 << " " << dequeuedValue3 << " " << dequeuedValue4 << " " << dequeuedValue5 << " " << dequeuedValue6 << std::endl;
    std::cout << "Front Value: " << frontValue << std::endl;
    std::cout << "Is Queue Empty? " << (isEmpty ? "Yes" : "No") << std::endl;

    return 0;
}
