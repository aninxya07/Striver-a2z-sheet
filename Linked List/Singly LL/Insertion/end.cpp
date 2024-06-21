#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

Node* Arr2LL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++) {
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

Node* insertAtEnd(Node* head, int element) {
    if(head == nullptr) {
        return new Node(element);
    }
    Node* mover = head;
    while(mover->next != nullptr) {   // when mover's next is null not when mover is null
        mover = mover->next;
    }
    Node* temp = new Node(element);  // a newly created node always points to null
    mover->next = temp;
    return head;
}

int main() {
    vector<int> arr = {2, 6, 5, 8, 3};
    Node* head = Arr2LL(arr);
    traversal(head);
    int k;
    cout<<"Enter the element value of performing insertion:"<<endl;
    cin>>k;
    head = insertAtEnd(head, k);
    traversal(head);
}