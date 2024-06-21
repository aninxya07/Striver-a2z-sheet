#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1 = NULL, Node* back1 = NULL) {
        data = data1;
        next = next1;
        back = back1;
    }
};

Node* Arr2LL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i], NULL, prev);
        prev->next = temp;
        prev = temp;
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

Node* insertAtEnd(Node* head, int val) {
    if(head == NULL)   // empty LL
        return new Node(val);

    if(head->next == NULL) {   // LL with a single node
        Node* temp = new Node(val);
        Node* prev = head;
        prev->back = temp;
        temp->next = prev;
        head = temp;
        return head;
    }

    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* temp = new Node(val);
    prev->next = temp;
    temp->back = prev;
    tail->back = temp;
    temp->next = tail;
    return head;
}

int main() {
    vector <int> arr = {2, 6, 5, 8, 3};
    Node* head = Arr2LL(arr);
    traversal(head);
    int val;
    cout<<"Enter a value to insert:"<<endl;
    cin>>val;
    cout<<"After insertion"<<endl;
    head = insertAtEnd(head, val);
    traversal(head);
}