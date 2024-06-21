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
    cout<<"LL creation successfull!"<<endl;
    return head;
}

bool search(Node* head, int key) {
    Node* temp = head;
    while(temp) {
        if(temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 5, 3};
    Node* head = convertArr2LL(arr);
    
    int key;
    cout<<"Enter an element you want to search:"<<endl;
    cin>>key;

    if (search(head, key)) {
        cout << "Key " << key << " found in the linked list" << endl;
    }
    else {
        cout << "Key " << key << " not found in the linked list" << endl;
    }
}