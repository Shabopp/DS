#include<iostream>
using namespace std;
//2 approaches -- 1.using counter variable & replacing the, 
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

node* sort012(node* head)
{
    if (head == NULL)
        return NULL;
    int zerocnt=0;
    int onecnt=0;
    int twocnt=0;
    node* curr = head;

    while (curr != NULL)
{
        
            if (curr->data==0)
            {
               zerocnt++;
            }
            else if(curr->data==1)
            {
               onecnt++;
            }
            else{
                twocnt++;
            }
        
        curr = curr->next; 
}
curr=head;
    while (curr != NULL)
{
        
            if (zerocnt!=0)
            {   
                curr->data=0;
               zerocnt--;
            }
            else if(onecnt!=1)
            {   
               curr->data=1;
               onecnt--;
            }
            else{
                curr->data=2;
                twocnt--;
            }
        
        curr = curr->next; 
}
return head;

}

int main()
{
    node* node1 = new node(0);
    node* head = node1;

    insertionAthead(head, 2);
    insertionAthead(head, 0);
    insertionAthead(head, 1);
    insertionAthead(head, 1);
    print(head);
    
     

    sort012(head);
    print(head);
    

    return 0;
}
