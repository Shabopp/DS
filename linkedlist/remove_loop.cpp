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
node* startingnode(node* head)
{
    if (head == NULL)
        return NULL;

    node* slow = head;
    node* intersection = floyd_algo(head);
    

    while ( slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
        if(intersection==slow)
        {
            return slow;
        }
    }

    return NULL;
}
void remove_loop(node* head)
{
     if (head == NULL)
        return;
    
node* startofnode= startingnode(head);
node* temp=startofnode;
while(temp->next != startofnode )
{
    temp=temp->next;

}
temp->next=NULL;


}
int main()
{
    node* node1 = new node(50);
    node* head = node1;

    insertionAthead(head, 20);
    insertionAthead(head, 15);
    insertionAthead(head, 4);
    insertionAthead(head, 10);
    //print(head);
    //creating loop
    head->next->next->next->next->next = head->next->next;


    node* ans = floyd_algo(head);
    if (ans  != nullptr)
    {
        cout << "cycle is present " << endl;
    }
    else
    {
        cout << "cycle is absent" << endl;
    }
    node* start = startingnode(head);
    cout << "cycle starts from " << start ->data << endl;
    remove_loop(head);
    print(head);
    

    return 0;
}
