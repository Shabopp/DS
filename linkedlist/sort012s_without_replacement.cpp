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

void insertionAthead(node* &head, int d) {
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

void print(node* &head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(node* &tail, node* curr ) {
    tail -> next = curr;
    tail = curr;
}

node* sortList(node* head)
{
    node* zeroHead = new node(-1);
    node* zeroTail = zeroHead;
    node* oneHead = new node(-1);
    node* oneTail = oneHead;
    node* twoHead = new node(-1);
    node* twoTail = twoHead;
    
    node* curr = head;
    
    // create separate lists for 0s, 1s, and 2s
    while(curr != NULL) {
        
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }       
        curr = curr -> next;
    }
    
    // merge 3 sublists
    
    // 1s list is not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
        // 1s list is empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
    // setup head
    head = zeroHead -> next;
    
    // delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}

int main() {
    node* node1 = new node(0);
    node* head = node1;

    insertionAthead(head, 2);
    insertionAthead(head, 0);
    insertionAthead(head, 1);
    insertionAthead(head, 1);

    cout << "Original Linked List: ";
    print(head);

    head = sortList(head);

    cout << "Sorted Linked List: ";
    print(head);

    return 0;
}
