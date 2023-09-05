#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~node() {
        int value = this->data;
        // Memory free
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertionAthead(node* &head, int d)
{
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertionAttail(node* &tail, int d)
{
    node* temp = new node(d);
    if (tail == NULL) {
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void insertionAtpos(node* &tail, node* &head, int pos, int d)
{
    if (pos == 1)
    {
        insertionAthead(head, d);
        return;
    }

    node* temp = head;
    int cnt = 1;

    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertionAttail(tail, d);
        return;
    }

    node* nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void deleteNode(int position, node* &head) {

    // Deleting first or start node
    if (position == 1) {
        node* temp = head;
        head = head->next;
        // Memory free start node
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // Deleting any middle node or last node
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while (cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

    }
}

void print(node* &head) {

    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;

    insertionAthead(head, 20);
    print(head);

    insertionAthead(head, 40);
    insertionAttail(tail, 70);
    print(head);
    insertionAtpos(tail, head, 3, 100);
    print(head);

    deleteNode(5, head);
    print(head);

    return 0;
}
