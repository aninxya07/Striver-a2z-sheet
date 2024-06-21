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

Node* insertAtStart(Node* head, int val) {
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
    return head;
}

Node* insertAtEnd(Node* head, int val) {
    if(head == nullptr)
        return new Node(val);
    Node* mover = head;
    Node* temp = new Node(val);
    while(mover->next != nullptr) {
        mover = mover->next;
    }
    mover->next = temp;
    return head;
}

Node* insertAtPosition(Node* head, int val, int pos) {
    if(head == nullptr)
        return nullptr;
    if(pos == 1) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        return head;
    }
    Node* mover = head;
    int count = 0;
    while(mover) {
        count++;
        if(count == pos-1) {
            Node* temp = new Node(val);
            temp->next = mover->next;
            mover->next = temp;
            break;
        }
        mover = mover->next;
    }
    return head;
}

Node* insertBeforeElement(Node* head, int newVal, int oldVal) {
    if(head == nullptr)
        return nullptr;
    if(head->data == oldVal) {
        Node* temp = new Node(newVal);
        temp->next = head;
        head = temp;
        return head;
    }
    Node* mover = head;
    while(mover->next != nullptr) {
        if(mover->next->data == oldVal) {
            Node* temp = new Node(newVal);
            temp->next = mover->next;
            mover->next = temp;
            break;
        }
        mover = mover->next;
    }
    return head;
}

int main() {
    vector<int> arr = {2, 5, 6, 8, 3};
    Node* head = Arr2LL(arr);
    traversal(head);
    int newVal;
    cout<<"Enter the value of the new element:"<<endl;
    cin>>newVal;
    int oldVal;
    cout<<"Enter the value of old element:"<<endl;
    cin>>oldVal;
    head = insertBeforeElement(head, newVal, oldVal);
    traversal(head);
}