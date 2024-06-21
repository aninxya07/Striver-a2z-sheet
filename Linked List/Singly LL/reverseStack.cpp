#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* back;

    public:   // constructor
    Node(int data1, Node * next1 = nullptr, Node* back1 = nullptr) {
        data = data1;
        next = next1;
        back = back1;
    }
};

Node * convertArr2LL(vector<int> arr) {
    if (arr.empty())
        return nullptr;
        
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void traversal(Node* head) {
    Node* mover = head;
    while(mover) {
        cout<<mover->data<<" ";
        mover = mover->next;
    }
    cout<<endl;
}

Node* reverseUsingStack(Node* head) {
    stack<int> st;
    Node* temp = head;
    while(temp) {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp) {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

int main() {
    vector <int> arr = {12, 5, 6, 4, 8};
    Node* head = convertArr2LL(arr);
    traversal(head);
    head = reverseUsingStack(head);
    traversal(head);
}