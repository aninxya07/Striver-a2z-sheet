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

//you've to insert a value before the mentioned value
//which is already there somewhere in the LL

Node* insertBeforeValue(Node* head, int newVal, int oldVal) {
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
    vector<int> arr = {2, 6, 5, 8, 3};
    Node* head = Arr2LL(arr);
    traversal(head);
    int newVal;
    cout<<"Enter the value of new element to performing insertion:"<<endl;
    cin>>newVal;
    int oldVal;
    cout<<"Enter the old value before which insertion will be performed:"<<endl;
    cin>>oldVal;
    head = insertBeforeValue(head, newVal, oldVal);
    traversal(head);
}