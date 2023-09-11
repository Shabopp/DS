#include <iostream>
#include <stack>

using namespace std;

void solve(stack<int>& inputStack, int size, int count) {
    if (count == size / 2) {  
        inputStack.pop();
        return; 
    }
    int num = inputStack.top();
    inputStack.pop();
    // Recursive call
    solve(inputStack, size, count + 1);
    inputStack.push(num);
}

void deleteMiddle(stack<int>& inputStack, int N) {
    int count = 0;
    solve(inputStack, N, count);
}

int main() {
    stack<int> myStack;

    // Push some elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    cout << "Original stack:" << endl;
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    // Push the elements again
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    // Delete the middle element
    deleteMiddle(myStack, myStack.size());

    cout << "Stack after deleting middle element:" << endl;
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
