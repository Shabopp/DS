#include <iostream>

using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

node* findMid(node* head) {
    node* slow = head;
    node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* left, node* right) {

    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    node* ans = new node(-1);
    node* temp = ans;

    // Merge 2 sorted Linked Lists
    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;

}

node* mergeSort(node* head) {
    // Base case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Break linked list into 2 halves, after finding mid
    node* mid = findMid(head);

    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    // Recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge both left and right halves
    node* result = merge(left, right);

    return result;
}

// Function to print the linked list
void printList(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a sample linked list
    node* head = new node(5);
    head->next = new node(2);
    head->next->next = new node(9);
    head->next->next->next = new node(1);
    head->next->next->next->next = new node(6);

    cout << "Original Linked List:" << endl;
    printList(head);

    // Sort the linked list using merge sort
    head = mergeSort(head);

    cout << "Sorted Linked List:" << endl;
    printList(head);

    return 0;
}
