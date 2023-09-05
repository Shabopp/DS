#include <iostream>

using namespace std;

// Define the Node structure
class Node {
public:
    int data;
    Node* next;
    Node* random;
    Node(int d) : data(d), next(nullptr), random(nullptr) {}
};

// Function to copy a linked list with random pointers
Node* copyList(Node* head) {
    if (!head) return nullptr;

    // Step 1: Create a clone list and insert nodes at the tail
    Node* cloneHead = nullptr;
    Node* cloneTail = nullptr;
    
    Node* temp = head;
    while (temp != nullptr) {
        Node* newNode = new Node(temp->data);
        if (!cloneHead) {
            cloneHead = newNode;
            cloneTail = newNode;
        } else {
            cloneTail->next = newNode;
            cloneTail = newNode;
        }
        temp = temp->next;
    }

    // Step 2: Insert clone nodes in between the original list
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    
    while (originalNode != nullptr && cloneNode != nullptr) {
        Node* next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;
        
        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    // Step 3: Copy random pointers
    originalNode = head;
    cloneNode = cloneHead;
    
    while (originalNode != nullptr && cloneNode != nullptr) { 
        if (originalNode->random != nullptr) {
            cloneNode->random = originalNode->random->next;
        } else {
            cloneNode->random = nullptr;
        }
        cloneNode = cloneNode->next;
        originalNode = originalNode->next;
    }

    // Step 4: Revert changes made in step 2 (restore the original list)
    originalNode = head;
    cloneNode = cloneHead;
    
    while (originalNode && cloneNode) {
        originalNode->next = originalNode->next ? originalNode->next->next : originalNode->next;
        cloneNode->next = cloneNode->next ? cloneNode->next->next : cloneNode->next;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    // Step 5: Return the cloned list
    return cloneHead;
}

// Function to print the linked list with random pointers
void printRandom(Node* head) {
    while (head != nullptr) {
        cout << "Node data: " << head->data << " ";
        if (head->random != nullptr) {
            cout << "Random Node data: " << head->random->data;
        } else {
            cout << "Random Node data: NULL";
        }
        cout << endl;
        head = head->next;
    }
}

int main() {
    // Create a sample linked list with random pointers
    Node* head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    head->random = node3;
    node2->random = head;
    node3->random = node2;
    node4->random = node3;

    // Copy the linked list
    Node* clonedHead = copyList(head);

    // Print the original linked list with random pointers
    cout << "Original Linked List with Random Pointers:" << endl;
    printRandom(head);

    // Print the copied linked list with random pointers
    cout << "Copied Linked List with Random Pointers:" << endl;
    printRandom(clonedHead);

    return 0;
}
