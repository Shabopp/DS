#include <iostream>

using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* child;
    Node() : data(0), next(nullptr), child(nullptr) {}
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node* next, Node* child) : data(x), next(next), child(child) {}
};

Node* merge(Node* f, Node* s) {

    if (f == NULL) {
        return s;
    }

    if (s == NULL) {
        return f;
    }

    Node* head = new Node(-1);
    Node* tmp = head;

    while (f != NULL && s != NULL) {
        if (f->data > s->data) {
            tmp->child = s;
            tmp = s;
            s = s->child;
        } else {
            tmp->child = f;
            tmp = f;
            f = f->child;
        }
    }

    while (f != NULL) {
        tmp->child = f;
        tmp = f;
        f = f->child;
    }

    while (s != NULL) {
        tmp->child = s;
        tmp = s;
        s = s->child;
    }

    return head->child;
}

Node* flattenLinkedList(Node* head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* down = head;
    Node* right = flattenLinkedList(head->next);
    down->next = NULL;
    Node* ans = merge(down, right);

    return ans;
}

int main() {
    // Create a sample linked list with child nodes
    Node* head = new Node(1);
    head->child = new Node(2);
    head->child->child = new Node(3);

    head->next = new Node(4);
    head->next->child = new Node(5);
    head->next->child->child = new Node(6);

    head->next->next = new Node(7);

    // Flatten the linked list
    Node* flattened = flattenLinkedList(head);

    // Print the flattened linked list
    while (flattened != nullptr) {
        cout << flattened->data << " ";
        flattened = flattened->child;
    }
    cout << endl;

    return 0;
}
