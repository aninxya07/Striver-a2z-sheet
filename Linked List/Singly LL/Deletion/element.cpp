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

Node* deletionOfElement(Node* head, int k) {
    if(head == nullptr)
        return head;
    if(head->data == k) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp) {
        if(temp->data == k) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    vector <int> arr = {12, 5, 6, 4, 8};
    Node* head = convertArr2LL(arr);
    cout<<"Before deletion at the begining"<<endl;
    traversal(head);
    int k;
    cout<<"Enter the element of performing deletion:"<<endl;
    cin>>k;
    cout<<"After deletion"<<endl;
    head = deletionOfElement(head, k);  // updates the new head
    traversal(head);
}