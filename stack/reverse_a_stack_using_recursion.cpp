#include <iostream>
#include <stack>

using namespace std;

void insertatbottom(stack<int>& s, int x) {
    // Base case
    if (s.empty()) {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    // Recursive call
    insertatbottom(s, x);

    s.push(num);
}

void reverseStack(stack<int>& stack) {
    if (stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();
    reverseStack(stack);

    insertatbottom(stack, num);
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
    stack<int> printStack = myStack;

    while (!printStack.empty()) {
        cout << printStack.top() << " ";
        printStack.pop();
    }
    cout << endl;

    // Reverse the stack
    reverseStack(myStack);

    cout << "Reversed stack:" << endl;
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
