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
    if (arr.empty())
        return NULL;
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

Node* deletionAtPosition(Node* head, int k) {
    if(head == NULL)  // empty doubly ll
        return NULL;
    
    int count = 0;
    Node* temp = head;
    while(temp) {  // taking the pointer temp to the kth position node
        count++;
        if(count == k)
            break;
        temp = temp->next;
    }

    if (temp == NULL) {     // k is out of bounds
        cout << "Position out of bounds" << endl;
        return head;
    }

    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL) {  // single node doubly ll
        delete temp;
        return NULL;
    }

    else if(prev == NULL) {  // standing at head
        head = head->next;
        head->back = NULL;
        temp->next = NULL;
        delete temp;
        return head;
    }
            
    else if(front == NULL) {  // standing at tail
        prev->next = NULL;
        delete temp;
        return head;
    }
            
    // anywhere in the middle
    prev->next = front;
    front->back = prev;
    temp->back = NULL;
    temp->next = NULL;
    delete temp;
    return head;
}

int main() {
    vector <int> arr = {2, 5, 6, 4, 8};
    Node* head = Arr2LL(arr);
    traversal(head);
    int k;
    cout<<"Enter the position to perform deletion:"<<endl;
    cin>>k;
    cout<<"After deletion"<<endl;
    head = deletionAtPosition(head, k);
    traversal(head);
}