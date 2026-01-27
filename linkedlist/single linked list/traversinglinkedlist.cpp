#include <iostream>
using namespace std;

// Node structure for singly linked list
// struct ka default access 'public' hota hai
struct Node {
    int data;    // value stored in the node
    Node* next;  // pointer to the next node
};

// Function to insert a new node at the end of the list
void insertEnd(Node*& start, int value) {
    Node* newNode = new Node(); // create a new node dynamically
    newNode->data = value;      // assign value to the new node
    newNode->next = nullptr;    // last node's next will be NULL

    if (start == nullptr) {     // if list is empty
        start = newNode;        // new node becomes the first node
        return;
    }

    Node* temp = start;         // temporary pointer to traverse
    while (temp->next != nullptr) { // go to the last node
        temp = temp->next;
    }
    temp->next = newNode;       // link the last node to the new node
}

// Function to print/traverse the linked list
void traverse(Node* start) {
    Node* temp = start;         // start from the head
    while (temp != nullptr) {   // go until the end (NULL)
        cout << temp->data << " -> "; // print data
        temp = temp->next;      // move to next node
    }
    cout << "NULL" << endl;     // end of list
}

int main() {
    cout << "Singly Linked List Example:" << endl;

    Node* start = nullptr;      // initially list is empty

    // Insert nodes at the end
    insertEnd(start, 10);
    insertEnd(start, 20);
    insertEnd(start, 30);

    // Print the linked list
    traverse(start);

    return 0;
}
