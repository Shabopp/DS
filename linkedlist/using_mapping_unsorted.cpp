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

void remove_duplicates_unsorted(node* head)
{
    if (head == NULL)
        return;

    map<int, bool> seen;
    node* curr = head;
    node* prev = NULL;

    while (curr != NULL)
    {
        if (seen[curr->data]) {
            // Duplicate found, remove the node
            prev->next = curr->next;
            delete(curr);
            curr = prev->next;
        }
        else {
            // Not a duplicate, mark it as seen and move forward
            seen[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
}

int main()
{
    node* node1 = new node(990);
    node* head = node1;

    insertionAthead(head, 90);
    insertionAthead(head, 20);
    insertionAthead(head, 990);
    insertionAthead(head, 20);

    cout << "Original Linked List: ";
    print(head);

    remove_duplicates_unsorted(head);

    cout << "Linked List after removing duplicates: ";
    print(head);

    return 0;
}
/*
Initialize a map seen of type std::map<int, bool> to keep track of unique values encountered in the linked list. 
The keys in the map will be the unique values,
 and the corresponding values are of type bool and are not used for any specific purpose; they are only used to indicate the presence of a value.

Initialize two pointers, curr and prev, to traverse the linked list. curr will point to the current node, and prev will point to the previous node.

Start iterating through the linked list from the beginning, beginning with curr pointing to the head node.

In each iteration, check if the current node's data value is already present in the seen map. This is done using the line if (seen[curr->data]).

If the value is found in the map (i.e., seen[curr->data] is true), it means a duplicate has been encountered.
In this case, we update the prev->next pointer to skip the current node (curr) and point it to the next node (curr->next).
We then delete the current node (delete(curr)) to free up memory.
Finally, we update curr to point to the next node after the duplicate (i.e., curr = prev->next).
If the current node's data value is not found in the seen map (i.e., seen[curr->data] is false), it means the value is unique.

In this case, we mark the value as "seen" by setting seen[curr->data] to true.
We update prev to point to the current node (prev = curr) since it's not a duplicate.
We then move curr to the next node in the list (curr = curr->next) to continue checking the remaining nodes.
Repeat steps 4 and 5 until curr reaches the end of the linked list (i.e., curr becomes NULL).

After the loop, all duplicates have been removed from the linked list, and you're left with a modified linked list containing only unique values.

This implementation ensures that only the duplicates are removed, and the order of the remaining unique values in the linked list is preserved.
*/