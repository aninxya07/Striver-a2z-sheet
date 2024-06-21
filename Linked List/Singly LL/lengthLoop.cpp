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

int lengthLoop(Node* head) {   // brute force approach
    if(head == NULL || head->next == NULL)
        return 0;
    map<Node*, int> mp;
    Node* temp = head;
    int timer = 0;
    while(temp) {
        if(mp.find(temp) != mp.end()) {
            int value = mp[temp];
            return (timer - value);
        }
        mp[temp] = timer;
        timer++;
    }
    return 0;
}

int lengthLoop(Node* head) {  // optimal approach using tortoise-hare algo
    if(head == NULL || head->next == NULL)
        return 0;

    int count = 0;
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            return findLength(slow, fast);
        }
    }
    return 0;
}

int findLength(Node* slow, Node* fast) {
    int count = 1;
    fast = fast->next;
    while(slow != fast) {
        count++;
        fast = fast->next;
    }
    return count;
}

int main() {
    vector<int> arr = {9, 9, 9, 9}; // you can't a make a loop LL here, so better just remember it as concept!
    Node* head = Arr2LL(arr);
    traversal(head);
    cout<<"Length of any existing loop:"<<endl;

}