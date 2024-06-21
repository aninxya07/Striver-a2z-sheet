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

Node* getKthNode(Node* temp, int k) {
    k -= 1;
    
    while(temp!=NULL && k>0) {
        k--;
        temp = temp->next;
    }
    return temp;
}

Node* reverseLL(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* current = head;
    Node* temp = NULL;

    while (current != NULL) {
        Node* front = current->next;
        current->next = temp;
        temp = current;
        current = front;
    }
    return temp;
}

Node* reverseKGroup(Node* head, int k) {
    Node* temp = head;
    Node* prevLast = NULL;

    while(temp!=NULL) {
        Node* kthNode = getKthNode(temp, k);
    
        if(kthNode == NULL) {
            if(prevLast) {
                prevLast->next = temp;
            }
            break;
        }
        
        Node* nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseLL(temp);
        
        if(temp == head)
            head = kthNode;
        else {
            prevLast->next = kthNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    Node* head = Arr2LL(arr);
    traversal(head);
    int k;
    cout<<"Enter the value of k:"<<endl;
    cin>>k;
    cout<<"After reversing the LL by K group:"<<endl;
    head = reverseKGroup(head, k);
    traversal(head);
}