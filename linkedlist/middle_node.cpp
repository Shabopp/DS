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


};
void insertionAthead(node* &head, int d)
{
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
node* getmiddle(node* head)
{
    if (head == nullptr)
        return nullptr;

    node* slow = head;
    node* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


int main()
{
    node* node1 = new node(1);
    node* head = node1;

    insertionAthead(head, 2);
    insertionAthead(head, 3);
    insertionAthead(head, 4);
    insertionAthead(head, 5);
    print(head);

    node* middle = getmiddle(head);
    if (middle != nullptr)
    {
        cout << "Middle node data: " << middle->data << endl;
    }
    else
    {
        cout << "The list is empty." << endl;
    }

    return 0;
}
