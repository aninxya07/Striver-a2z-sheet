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

Node* deletionAtBegining(Node* head) {
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deletionAtEnd(Node* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

Node* deletionAtPosition(Node* head, int k) {
    if(head == nullptr)
        return head;
    if(k == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    int count = 0;
    while(temp) {
        count++;
        if(count == k) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* deletionOfElement(Node* head, int element) {
    if(head == nullptr) {
        return head;
    }
    if(head->data == element) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp) {
        if(temp->data == element) {
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
    vector<int> arr = {2, 6, 5, 8, 3};
    Node* head = Arr2LL(arr);
    traversal(head);
    int k;
    cout<<"Enter the element of performing deletion:"<<endl;
    cin>>k;
    head = deletionOfElement(head, k);
    traversal(head);
}