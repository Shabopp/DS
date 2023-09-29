#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverse(queue<int> &q, int k)
{
    stack<int> s;
    for(int i=0; i<k; i++)
    {
        int value = q.front();
        q.pop();
        s.push(value);
    }
    while (!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    int t = q.size() - k;
    while (t--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
}

int main()
{
    queue<int> q;
    int k = 3; // Replace with your desired 'k' value
    // Fill the queue with some values
    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }

    cout << "Original Queue: ";
    queue<int> originalQ = q; // Make a copy of the original queue
    while (!originalQ.empty()) {
        cout << originalQ.front() << " ";
        originalQ.pop();
    }

    cout << endl;

    // Reverse the first 'k' elements of the queue
    reverse(q, k);

    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
