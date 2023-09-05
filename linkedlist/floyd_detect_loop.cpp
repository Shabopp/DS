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
node* floyd_algo(node* head)
{
    if (head == NULL)
        return NULL;

    node* slow = head;
    node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow)
        {
            return slow;
        }
    }

    return NULL;
}


int main()
{
    node* node1 = new node(1);
    node* head = node1;

    insertionAthead(head, 2);
    insertionAthead(head, 3);
    insertionAthead(head, 4);
    insertionAthead(head, 5);
    //print(head);
    //creating loop
    head->next->next = head->next;


    node* ans = floyd_algo(head);
    if (ans  != nullptr)
    {
        cout << "cycle is present " << ans ->data << endl;
    }
    else
    {
        cout << "cycle is absent" << endl;
    }

    return 0;
}
