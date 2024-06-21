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

Node* convertArr2LL(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int length(Node* head) {
    Node* temp = head;
    int count=0;
    while(temp) {
        temp = temp->next;
        count++;
    }
    return count;
}

int main() {
    vector<int> arr = {2, 4, 6, 5, 8, 3};
    Node* head = convertArr2LL(arr);
    cout<<length(head);
}