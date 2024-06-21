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

int helper(Node* temp) {
    if(temp == NULL)
        return 1;
    int carry = helper(temp->next);

    temp->data = temp->data + carry;
    if(temp->data < 10)
        return 0;
    temp->data = 0;
    return 1;
}

Node* addOne(Node* head) {
    int carry = helper(head);
    if(carry == 1) {
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

int main() {
    vector<int> arr = {9, 9, 9, 9};
    Node* head = Arr2LL(arr);
    traversal(head);
    cout<<"After adding 1 to the LL:"<<endl;
    head = addOne(head);
    traversal(head);
}