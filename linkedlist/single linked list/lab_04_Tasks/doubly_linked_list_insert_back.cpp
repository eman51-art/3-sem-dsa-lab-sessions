#include <iostream>
using namespace std;

// Node class for Doubly Linked List
class Node {
public:
    int data;       // Store the value of the node
    Node* next;     // Pointer to the next node
    Node* prev;     // Pointer to the previous node

    // Constructor to create a node with a value
    Node(int val) {
        data = val;
        next = nullptr;  // Initially, no next node
        prev = nullptr;  // Initially, no previous node
    }
};

// Doubly Linked List class
class doublelinkedlist {
public:
    Node* head = nullptr; // Pointer to the first node
    Node* tail = nullptr; // Pointer to the last node

    // Function to insert a node at the back (end of the list)
    void insertAtBack(int val) {
        Node* newnode = new Node(val);  // Create new node

        if (head == nullptr) {          // If list is empty
            head = tail = newnode;      // New node is both head and tail
            return;
        }

        tail->next = newnode;           // Old tail's next points to new node
        newnode->prev = tail;           // New node's prev points to old tail
        tail = newnode;                 // Update tail to new node
    }

    // Function to display the list from head to tail
    void display() {
        Node* temp = head;              // Start from head
        while (temp != nullptr) {
            cout << temp->data << " -> "; // Print node value
            temp = temp->next;           // Move to next node
        }
        cout << "null" << endl;          // End of list
    }
};

int main() {
    doublelinkedlist dl;

    // Insert nodes at the back
    dl.insertAtBack(10);  // List: 10
    dl.insertAtBack(20);  // List: 10 -> 20
    dl.insertAtBack(30);  // List: 10 -> 20 -> 30

    cout << "Doubly Linked List:" << endl;
    dl.display();  // Output: 10 -> 20 -> 30 -> null

    return 0;
}
