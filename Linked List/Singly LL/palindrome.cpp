#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int data1, Node* next1 = nullptr, Node* prev1 = nullptr) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* Arr2LL(const vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (size_t i = 1; i < arr.size(); ++i) {
        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    return head;
}

void traversal(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* Reverse(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* current = head;
    Node* temp = NULL;

    while (current != NULL) {
        Node* front = current->next;
        current->next = temp;
        temp = current;
        current = front;
    }
    return temp;
}

bool palindrome(Node* head) {
    if(head == NULL || head->next == NULL)
        return true;
    Node* fast = head;
    Node* slow = head;
    while(fast->next!=NULL && fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = Reverse(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second != NULL) {
        if(first->data != second->data) {
            Reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    Reverse(newHead);
    return true;
}

int main() {
    vector<int> arr = {1, 2, 3, 3, 2, 1};
    Node* head = Arr2LL(arr);
    traversal(head);
    cout<<"Palindrome check!"<<endl;
    if(palindrome(head))
        cout<<"true";
    else
        cout<<"false";
}