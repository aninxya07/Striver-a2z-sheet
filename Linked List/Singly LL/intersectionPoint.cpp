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

Node* getIntersectNode(Node* head1, Node*head2) {
    if(head1 == NULL || head2 == NULL)
        return NULL;
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if(temp1 == temp2)
            return temp1;

        if(temp1 == NULL)
            temp1 = head2;

        if(temp2 == NULL)
            temp2 = head1;
    }
    return temp1;
}

int main() {
    vector<int> arr1 = {4,1,8,4,5};
    vector<int> arr2 = {5, 6, 1};
    Node* head1 = Arr2LL(arr1);
    Node* head2 = Arr2LL(arr2);
    traversal(head1);
    traversal(head2);
    

    return 0;
}