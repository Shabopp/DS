#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void reverse(queue<int> &q) { // Pass the queue by reference
    stack<int> s;

    // Push elements from the queue into the stack
    while (!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    // Pop elements from the stack back into the queue
    while (!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }
}

int main() {
    queue<int> q;

    // Populate the queue
    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }

    cout << "Original queue:" << endl;
    queue<int> originalQueue = q; // Copy for display
    while (!originalQueue.empty()) {
        cout << originalQueue.front() << " ";
        originalQueue.pop();
    }
    cout << endl;

    // Reverse the queue
    reverse(q);

    cout << "Reversed queue:" << endl;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
