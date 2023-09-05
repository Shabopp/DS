#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
Node<T>* solve(Node<T>* first, Node<T>* second) {
    if (first->next == NULL) {
        first->next = second;
        return first;
    }

    Node<T>* curr1 = first;
    Node<T>* next1 = curr1->next;

    Node<T>* curr2 = second;
    Node<T>* next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL) {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL) {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

template <typename T>
Node<T>* sortTwoLists(Node<T>* first, Node<T>* second) {
    if (first == NULL)
        return second;

    if (second == NULL)
        return first;

    if (first->data <= second->data) {
        return solve(first, second);
    }
    else {
        return solve(second, first);
    }
}

template <typename T>
void printList(Node<T>* head) {
    Node<T>* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create two sorted linked lists.
    Node<int>* node1 = new Node<int>(10);
    Node<int>* head1 = node1;
    node1->next = new Node<int>(30);
    node1->next->next = new Node<int>(50);

    Node<int>* node2 = new Node<int>(20);
    Node<int>* head2 = node2;
    node2->next = new Node<int>(240);

    cout << "First Sorted Linked List: ";
    printList(head1);

    cout << "Second Sorted Linked List: ";
    printList(head2);

    // Merge the sorted linked lists.
    Node<int>* mergedList = sortTwoLists(head1, head2);

    cout << "Merged Sorted Linked List: ";
    printList(mergedList);

    return 0;
}
