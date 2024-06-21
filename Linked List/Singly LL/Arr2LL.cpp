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

int main() {
    vector <int> arr = {12, 5, 6, 4, 8};
    Node* head = convertArr2LL(arr);
    cout<<head->data;
}