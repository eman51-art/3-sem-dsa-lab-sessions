#include <iostream>
using namespace std;

// Note: 
// struct ka default access public hota hai
// class ka default access private hota hai

// Node structure for singly linked list
struct Node {
    int data;      // store value of the node
    Node* next;    // pointer to next node
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;        // start from head
    while(temp != nullptr) {  // traverse until NULL
        cout << temp->data << " -> ";
        temp = temp->next;    // move to next node
    }
    cout << "NULL" << endl;   // end of list
}

int main() {
    cout << "Linked List Example" << endl;

    // Step 1: Create nodes dynamically
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Step 2: Assign data and links
    head->data = 100;       // first node value
    head->next = second;    // first node points to second

    second->data = 200;     // second node value
    second->next = third;   // second node points to third

    third->data = 300;      // third node value
    third->next = nullptr;  // last node points to NULL

    // Step 3: Print the linked list
    cout << "Singly Linked List: " << endl;
    printList(head);

    return 0;
}
