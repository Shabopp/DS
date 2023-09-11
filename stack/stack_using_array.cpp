#include <iostream>
using namespace std;

class Stack {
    // Properties
    int *arr;
    int size;
    int top;

public:
    // Constructor
    Stack(int size) {
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(int num) {
        if (top < size - 1) {
            top++;
            arr[top] = num;
        } else {
            cout << "Stack overflow" << endl;
        }
    }

    // Pop an element from the stack
    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack is underflowed" << endl;
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Get the top element of the stack
    int peek() {
        if (top >= 0) {
            return arr[top];
        }
        // Handle the case where the stack is empty
        cout << "Stack is empty" << endl;
        return -1;
    }
};

int main() {
    Stack myStack(5); // Create a stack of size 5

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Top element: " << myStack.peek() << endl; // Output: 3

    myStack.pop();
    cout << "Top element after pop: " << myStack.peek() << endl; // Output: 2

    myStack.pop();
    myStack.pop();
    myStack.pop(); // Trying to pop from an empty stack

    if (myStack.isEmpty()) {
        cout << "Stack is empty" << endl; // Output: Stack is empty
    }

    return 0;
}
