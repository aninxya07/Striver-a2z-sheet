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

Node* deletionAtStart(Node* head) {
    if(head == NULL || head->next == NULL)
        return NULL;
    Node* temp = head;
    head = head->next;
    head->back = NULL;
    temp->next = NULL;
    free(temp);   // delete prev (or)
    return head;
}

int main() {
    vector <int> arr = {12, 5, 6, 4, 8};
    Node* head = Arr2LL(arr);
    traversal(head);
    cout<<"After deletion"<<endl;
    head = deletionAtStart(head);
    traversal(head);
}