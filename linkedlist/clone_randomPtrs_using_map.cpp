#include <iostream>
#include <unordered_map>

using namespace std;

// Define the Node structure
class Node {
public:
    int data;
    Node* next;
    Node* random;
    Node(int d) : data(d), next(nullptr), random(nullptr) {}
};

// Function to insert a node at the tail of a linked list
void insertAtTail(Node* &head, Node* &tail, int d) {
    Node* newNode = new Node(d);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to copy a linked list with random pointers
Node* copyList(Node* head) {
    unordered_map<Node*, Node*> mp;
    Node* cloneHead = nullptr;
    Node* cloneNode = nullptr;
    Node* originalNode = head;

    while (originalNode != nullptr) {
        insertAtTail(cloneHead, cloneNode, originalNode->data);
        mp[originalNode] = cloneNode;
        originalNode = originalNode->next;
    }

    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != nullptr) {
        if (originalNode->random != nullptr) {
            cloneNode->random = mp[originalNode->random];
        } else {
            cloneNode->random = nullptr;
        }
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

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
