#include<iostream>
#include<map>
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
bool detectloop(node* head)
{
    if (head == NULL)
        return NULL;

    node* temp = head;
    map<node*,bool>visited;

    while (temp != NULL)
    {   
        if(visited[temp]==true)
        {
            return true;
        }
        visited[temp]=true;
        temp= temp->next;
        
        

    }

    return false;
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


    bool ans = detectloop(head);
    if (ans==true)
    {
        cout << "cycle is present " << endl;
    }
    else
    {
        cout << "cycle is absent" << endl;
    }

    return 0;
}
