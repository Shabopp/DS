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

node* remove_duplicates(node* head)
{
    if (head == NULL)
        return NULL;

    node* curr= head;


    while ( curr!= NULL)
    {
       
        if(curr->next != NULL && curr->data == curr->next->data)
        {   
            node* next_next = curr->next->next;
            node* NodeToDelete = curr->next;
            delete(NodeToDelete);
            curr->next=next_next;
          
        }
        else{
            curr=curr->next;
        }
    }

    return head;
}

int main()
{
    node* node1 = new node(50);
    node* head = node1;

    insertionAthead(head, 20);
    insertionAthead(head, 20);
    insertionAthead(head, 20);
    insertionAthead(head, 20);
    print(head);
  
  


    remove_duplicates(head);
    print(head);
    

    return 0;
}
