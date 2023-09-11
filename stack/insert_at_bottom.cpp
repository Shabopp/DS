#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int>& s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(top);
}

int main() {
    stack<int> myStack;

    // Push some elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Original stack:" << endl;
    stack<int> modifiedStack = myStack;

    while (!modifiedStack.empty()) {
        cout << modifiedStack.top() << " ";
        modifiedStack.pop();
    }
    cout << endl;

    int elementToInsert = 4;

    // Insert an element at the bottom of the same stack
    insertAtBottom(myStack, elementToInsert);

    cout << "Stack after inserting " << elementToInsert << " at the bottom:" << endl;
    
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}
