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

Node* insertBeforeElement(Node* head, int newVal, int oldVal) {
    if(head == NULL)   // empty LL
        return new Node(newVal);

    Node* tail = head;
    while(tail->next != NULL) {
        if(tail->data == oldVal) {
            break;
        }
        tail = tail->next;
    }

    if(head->data == oldVal) {
        Node* temp = new Node(newVal);
        Node* prev = head;
        prev->back = temp;
        temp->next = prev;
        head = temp;
        return head;
    }

    Node* prev = tail->back;
    Node* temp = new Node(newVal);
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
    int newVal;
    cout<<"Enter a new value to insert:"<<endl;
    cin>>newVal;
    int oldVal;
    cout<<"Enter an old value before which insertion will take placeoldVal:"<<endl;
    cin>>oldVal;
    cout<<"After insertion"<<endl;
    head = insertBeforeElement(head, newVal, oldVal);
    traversal(head);
}