#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1=NULL, Node* back1=NULL) {
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
    if(head == NULL)
        return NULL;
    
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    head->back = NULL;
    delete temp;
    return head;
}

Node* deletionAtEnd(Node* head) {
    if(head == NULL || head->next == NULL)
        return NULL;

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    Node* prev = temp->back;
    prev->next = NULL;
    temp->back = NULL;
    delete temp;
    return head;
}

Node* deletionAtPosition(Node* head, int pos) {
    if(head == NULL)
        return NULL;

    int count = 0;
    Node* temp = head;
    while(temp) {
        count++;
        if(count == pos) {
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if (temp == NULL) {
        cout << "Position out of bounds" << endl;
        return head;
    }

    if(prev == NULL && front == NULL) {
        delete temp;
        return NULL;
    }

    else if(prev == NULL) {
        head = head->next;
        head->back = NULL;
        temp->next = NULL;
        delete temp;
        return head;
    }

    else if(front == NULL) {
        prev->next = NULL;
        temp->back = NULL;
        delete temp;
        return head;
    }

    prev->next = front;
    front->back = prev;
    temp->back = NULL;
    temp->next = NULL;
    delete temp;
    return head;
}

Node* deletionBeforeElement(Node* head, int oldVal) {
    Node* temp = head;
    while(temp->next != NULL) {
        if(temp->data == oldVal) {
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL) {
        prev->next = NULL;
        temp->back = NULL;
        delete temp;
        return head;
    }

    prev->next = front;
    front->back = prev;
    temp->back = NULL;
    temp->next = NULL;
    delete temp;
    return head;
}

int main() {
    vector<int> arr = {2, 6, 5, 8, 3};
    Node* head = Arr2LL(arr);
    traversal(head);
    int pos;
    cout<<"Enter the position where deletion will take place:"<<endl;
    cin>>pos;
    cout<<"After deletion:"<<endl;
    head = deletionAtPosition(head, pos);
    traversal(head);

    return 0;
}