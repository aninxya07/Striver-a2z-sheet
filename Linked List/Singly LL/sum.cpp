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

Node* createList(const vector<int>& arr) {
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

Node* sumLists(Node* head1, Node* head2) {
    Node* dummy = new Node(-1);
    Node* p1 = head1;
    Node* p2 = head2;
    Node* current = dummy;
    int sum = 0, carry = 0;
    while(p1 != NULL || p2 != NULL) {
        sum = carry;
        if(p1)
            sum += p1->data;
        if(p2)
            sum += p2->data;
        Node* newNode = new Node(sum % 10);
        carry = sum / 10;
        current->next = newNode;
        current = current->next;
        if(p1)
            p1 = p1->next;
        if(p2)
            p2 = p2->next;
    }
    if(carry) {
        Node* newNode = new Node(carry);
        current->next = newNode;
    }
    Node* head = dummy->next;
    delete dummy;
    return head;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {5, 6, 7, 8};

    Node* head1 = createList(arr1);
    Node* head2 = createList(arr2);

    cout << "List 1: ";
    traversal(head1);

    cout << "List 2: ";
    traversal(head2);

    Node* sumHead = sumLists(head1, head2);

    cout << "Sum List: ";
    traversal(sumHead);

    return 0;
}