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

Node* sort012(Node* head) {
    Node* zeroDummy = new Node(-1);
    Node* zero = zeroDummy;

    Node* oneDummy = new Node(-1);
    Node* one = oneDummy;

    Node* twoDummy = new Node(-1);
    Node* two = twoDummy;

    if(head == NULL || head->next == NULL)
        return head;

    Node* temp = head;
    
    while(temp) {
        if(temp->data == 0) {
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data == 1) {
            one->next = temp;
            one = temp;
        }
        else {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    
    zero->next = (oneDummy->next)?oneDummy->next:twoDummy->next;

    //or you can avoid ternary operator and use if else

    // if(oneDummy->next)
    //     zero->next = oneDummy->next;
    // else
    //     zero->next = twoDummy->next;

    one->next = twoDummy->next;
    two->next = NULL;

    head = zeroDummy->next;
    delete zeroDummy, oneDummy, twoDummy;
    return head;
}

int main() {
    vector<int> arr = {2, 1, 0, 1, 0, 2, 0, 1, 1, 2, 1};
    Node* head = createList(arr);
    traversal(head);
    cout<<"After sorting all the 0, 1 & 2 contating nodes:"<<endl;
    head = sort012(head);
    traversal(head);
}