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

Node* insertAtPosition(Node* head, int element, int position) {
    if(head == nullptr)
        return nullptr;
    if(position == 1) {
        Node* temp = new Node(element);
        temp->next = head;
        head = temp;
        return head;
    }
    Node* mover = head;   
    int count = 0;
    while(mover) {
        count++;
        if(count == position-1) {
            Node* temp = new Node(element);
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
    int val;
    cout<<"Enter the element value of performing insertion:"<<endl;
    cin>>val;
    int pos;
    cout<<"Enter the desired position:"<<endl;
    cin>>pos;
    head = insertAtPosition(head, val, pos);
    traversal(head);
}