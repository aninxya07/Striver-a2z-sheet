#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    public:      //constructor
    Node(int data1, Node * next1) {
        data = data1;
        next = next1;
    }
};

int main() {
    vector <int> arr = {2, 5, 6, 4, 8};
    Node *y = new Node(arr[0], nullptr);
    cout<<y;   // stores the address of the node obj

    Node x = Node(arr[1], nullptr);
    cout<<(x.data);   // a new node obj is created & the data of the node is printed
    cout<<(x.next);   // address to the next node (which is null here) is printed as 0
}