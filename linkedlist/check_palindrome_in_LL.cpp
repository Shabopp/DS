#include <iostream>
//without using extra space b

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* getMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

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

bool isPalindrome(Node* head) {
    if (head->next == nullptr) {
        return true;
    }

    // Step 1 -> find Middle
    Node* middle = getMid(head);

    // Step 2 -> reverse List after Middle
    Node* temp = middle->next;
    middle->next = reverse(temp);

    // Step 3 - Compare both halves
    Node* head1 = head;
    Node* head2 = middle->next;

    while (head2 != nullptr) {
        if (head2->data != head1->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // Step 4 - repeat step 2
    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}

int main() {
    // Creating a sample linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    // Calling isPalindrome function and printing the result
    if (isPalindrome(head)) {
        std::cout << "The linked list is a palindrome." << std::endl;
    } else {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    // Clean up memory (free the allocated nodes)
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
