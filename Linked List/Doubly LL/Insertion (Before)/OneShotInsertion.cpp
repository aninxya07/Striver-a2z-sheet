#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1=NULL, Node* back1=NULL) {
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

Node* insertAtStart(Node* head, int val) {
    if(head == NULL)
        return new Node(val);
    Node* tail = head;
    Node* temp = new Node(val);
    temp->next = tail;
    tail->back = temp;
    head = temp;
    return head;
}

Node* insertAtEnd(Node* head, int val) {
    if(head == NULL)
        return new Node(val);
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

Node* insertBeforeElement(Node* head, int newVal, int oldVal) {
    if(head == NULL)
        return new Node(newVal);

    Node* tail = head;

    while(tail) {
        if(tail->data == oldVal) {
            break;
        }
        tail = tail->next;
    }

    if(head->data == oldVal) {
        Node* tail = head;
        Node* temp = new Node(newVal);
        temp->next = tail;
        tail->back = temp;
        head = temp;
        return head;        
    }

    Node* temp = new Node(newVal);
    Node* prev = tail->back;
    prev->next = temp;
    temp->back = prev;
    tail->back = temp;
    temp->next = tail;
    return head;
}

Node* insertAtPosition(Node* head, int val, int pos) {
    if(head == NULL)
        return new Node(val);
    int count = 0;
    Node* tail = head;
    while(tail != NULL) {
        count++;
        if(count == pos) {
            break;
        }
        tail = tail->next;
    }
    if(pos == 1) {
        Node* temp = new Node(val);
        Node* tail = head;
        temp->next = tail;
        tail->back = temp;
        head = temp;
        return head;
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
    vector<int> arr = {2, 4, 5, 8, 3};
    Node* head = Arr2LL(arr);
    traversal(head);
    int val;
    cout<<"Enter the new value to be inserted:"<<endl;
    cin>>val;
    int pos;
    cout<<"Enter the position where insertion will take place:"<<endl;
    cin>>pos;
    head = insertAtPosition(head, val, pos);
    traversal(head);
    return 0;
}