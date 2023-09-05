#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void insertAtTail(Node*& head, Node*& tail, int val) {
        Node* temp = new Node(val);
        // Empty list
        if (head == nullptr) {
            head = temp;
            tail = temp;
            return;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    Node* add(Node* first, Node* second) {
        int carry = 0;
        Node* ansHead = nullptr;
        Node* ansTail = nullptr;

        while (first != nullptr || second != nullptr || carry != 0) {
            int val1 = 0;
            if (first != nullptr)
                val1 = first->data;

            int val2 = 0;
            if (second != nullptr)
                val2 = second->data;

            int sum = carry + val1 + val2;
            int digit = sum % 10;

            // Create node and add to answer linked list
            insertAtTail(ansHead, ansTail, digit);

            carry = sum / 10;
            if (first != nullptr)
                first = first->next;

            if (second != nullptr)
                second = second->next;
        }
        return ansHead;
    }


    // Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* first, Node* second) {
        // Step 1 - Reverse input LL
        first = reverse(first);
        second = reverse(second);

        // Step 2 - Add 2 LL
        Node* ans = add(first, second);

        // Step 3 - Reverse the result
        ans = reverse(ans);

        return ans;
    }


int main() {
   

    // Creating two sample linked lists
    Node* first = new Node(9);
    first->next = new Node(9);
    first->next->next = new Node(9);

    Node* second = new Node(5);
    second->next = new Node(5);

    // Calling addTwoLists function and printing the result
    Node* result = addTwoLists(first, second);

    std::cout << "Sum of two linked lists: ";
    while (result != nullptr) {
        std::cout << result->data;
        if (result->next != nullptr) {
            std::cout << " -> ";
        }
        result = result->next;
    }
    std::cout << std::endl;

    // Clean up memory (free the allocated nodes)
    while (first != nullptr) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }

    while (second != nullptr) {
        Node* temp = second;
        second = second->next;
        delete temp;
    }

    return 0;
}
