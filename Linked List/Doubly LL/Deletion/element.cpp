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

Node* insertBeforeElement(Node* head, int oldVal) {
    Node* temp = head;
    while(temp->next != NULL) {
        if(temp->data == oldVal) {
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL) {
        prev->next = NULL;
        temp->back = NULL;
        delete temp;
        return head;
    }

    prev->next = front;
    front->back = prev;
    temp->back = NULL;
    temp->next = NULL;
    delete temp;
    return head;
}

int main() {
    vector<int> arr = {2, 5, 6, 8, 3};
    Node* head = Arr2LL(arr);
    traversal(head);
    int oldVal;
    cout<<"Enter the old element before which deletion will take place:"<<endl;
    cin>>oldVal;
    head = insertBeforeElement(head, oldVal);  // delete the head will never be asked in this case!
    traversal(head);
}