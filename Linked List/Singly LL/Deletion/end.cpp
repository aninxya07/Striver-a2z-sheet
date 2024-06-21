#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node * next;

    public:   // constructor
    Node(int data1, Node * next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

Node * convertArr2LL(vector<int> arr) {
    if (arr.empty())
        return nullptr;
        
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traversal(Node* head) {
    Node* temp = head;
    while(temp) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* deletionAtEnd(Node* head) {
    if(head == nullptr || head->next == nullptr)
        return nullptr;
    Node* temp = head;
    while(temp->next->next!=nullptr) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

// <-----------    OR     ------------>

// Node* deletionAtEnd(Node* head) {
//     if (head == nullptr || head->next == nullptr)
//         return nullptr;
    
//     Node* temp = head;
//     Node* ptr = head->next;

//     while (ptr->next != nullptr) {
//         temp = ptr;  // Move temp to point to the node before ptr
//         ptr = ptr->next;
//     }

//     free(ptr);  // Free the last node
//     temp->next = nullptr;  // Update the next pointer of the second-last node to nullptr

//     return head;
// }


int main() {
    vector <int> arr = {12, 5, 6, 4, 8};
    Node* head = convertArr2LL(arr);
    cout<<"Before deletion at the begining"<<endl;
    traversal(head);
    cout<<"After deletion"<<endl;
    head = deletionAtEnd(head);  // updates the new head
    traversal(head);
}