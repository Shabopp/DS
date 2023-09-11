#include <bits/stdc++.h>
using namespace std;

class TwoStack {
    int *arr;
    int size;
    int top1;
    int top2;

public:
    // Initialize TwoStack.
    TwoStack(int s) {
         this->size = s;
         arr = new int[s];
         top1 = -1;
         top2 = s;
    }
    
    // Destructor to release allocated memory.
    ~TwoStack() {
        delete[] arr;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if (top2 - top1 > 1) {   
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
       if (top2 - top1 > 1) {   
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if (top1 >= 0) {   
            int ans = arr[top1];
            top1--;
            return ans; // Return the popped element.
        } else {
            return -1; // Indicate that the stack is empty.
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 < size) {    
            int ans = arr[top2];
            top2++;
            return ans; // Return the popped element.
        } else {
            return -1; // Indicate that the stack is empty.
        }
    }
};

int main() {
    TwoStack ts(5);
    ts.push1(1);
    ts.push2(2);
    ts.push1(3);
    ts.push2(4);

    cout << "Popped from stack 1: " << ts.pop1() << std::endl; // Output: 3
    cout << "Popped from stack 2: " << ts.pop2() << std::endl; // Output: 4

    return 0;
}
