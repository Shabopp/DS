#include<iostream>
using namespace std;
//3 approaches
/*
1. using loops = tc=O(n^2);
               = sc=O(1);
2. using sorting & loops = tc=O(nlogn);
               = sc=O(1);
3. using mapping = tc=O(nlogn);
                 = sc=O(n);
*/
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

node* remove_duplicates_unsorted(node* head)
{
    if (head == NULL)
        return NULL;

    node* curr = head;

    while (curr != NULL)
    {
        node* temp = curr;
        while (temp->next != NULL)
        {
            if (curr->data == temp->next->data)
            {
                node* next_next = temp->next->next;
                delete(temp->next);
                temp->next = next_next;
            }
            else
            {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }

    return head;
}

int main()
{
    node* node1 = new node(990);
    node* head = node1;

    insertionAthead(head, 990);
    insertionAthead(head, 20);
    insertionAthead(head, 990);
    insertionAthead(head, 20);
    print(head);
    head.sort();
     
    // printing the forward list after sort
    for (auto it = head.begin(); it != head.end(); ++it)
        cout << ' ' << *it;

     remove_duplicates_unsorted(head);
    print(head);
    

    return 0;
}
