#include <iostream>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to add two numbers represented as linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* tail = dummyHead;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int digit1 = (l1 != nullptr) ? l1->val : 0;
        int digit2 = (l2 != nullptr) ? l2->val : 0;

        int sum = digit1 + digit2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        tail->next = new ListNode(digit);
        tail = tail->next;

        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }

    return dummyHead->next;
}

int main() {
    // Create two example linked lists
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Call the addTwoNumbers function
    ListNode* result = addTwoNumbers(l1, l2);

    // Print the result
    while (result != nullptr) {
        std::cout << result->val;
        if (result->next != nullptr) {
            std::cout << " -> ";
        }
        result = result->next;
    }

    // Clean up memory (free allocated nodes)
    while (l1 != nullptr) {
        ListNode* temp = l1;
        l1 = l1->next;
        delete temp;
    }
    while (l2 != nullptr) {
        ListNode* temp = l2;
        l2 = l2->next;
        delete temp;
    }
    return 0;
}
