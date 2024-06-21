#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int data1, Node* next1 = nullptr, Node* prev1 = nullptr) {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* Arr2LL(const vector<int>& arr) {
    if (arr.empty()) {
        return nullptr;
    }

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (size_t i = 1; i < arr.size(); ++i) {
        Node* newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    return head;
}

void traversal(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool detectLoop(Node* head) {   //brute force approach
    if(head == NULL)
        return NULL;
    map<Node*, int> mp;
    Node* temp = head;
    while(temp) {
        if(mp.find(temp) != mp.end()) {
            return true;
        }
        mp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

bool detectLoop(Node* head) {  // optimal approach using tortoise-hare algo
    if(head == NULL || head->next == NULL)
        return false;
    Node* slow = head;
    Node* fast = head;
    
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}

int main() {
    vector<int> arr = {9, 9, 9, 9}; // you can't a make a loop LL here, so better just remember it as concept!
    Node* head = Arr2LL(arr);
    traversal(head);
    cout<<"Checking for existence of any loop:"<<endl;

    if(detectLoop(head)) {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }

    // run all these loop problems in leetcode for verification!
}