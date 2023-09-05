#include <iostream>
#include <vector>
//using exta space = array ds
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool check(std::vector<int>& arr) {
    int s = 0;
    int e = arr.size() - 1;
    while (s <= e) {
        if (arr[s] != arr[e]) {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

bool isPalindrome(Node* head) {
    Node* temp = head;
    std::vector<int> ans;
    while (temp != nullptr) {
        ans.push_back(temp->data);
        temp = temp->next;
    }
    return check(ans);
}

int main() {
    // Creating a sample linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    // Calling isPalindrome function and printing the result
    if (isPalindrome(head)) {
        std::cout << "The linked list is a palindrome." << std::endl;
    } else {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    // Clean up memory (free the allocated nodes)
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
