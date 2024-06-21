#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1=NULL, Node* prev1=NULL) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* createList(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* current = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        current->next = temp;
        current = temp;
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

Node* oddEven(Node* head) {
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;

    while(even!=NULL && even->next!=NULL) {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 3};
    Node* head = createList(arr);
    traversal(head);
    cout<<"After odd even rearranging:"<<endl;
    head = oddEven(head);
    traversal(head);
}