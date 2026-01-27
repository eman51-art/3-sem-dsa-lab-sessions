#include <iostream>
using namespace std;

// Node class for Doubly Linked List
class Node {
public:
    int data;       // Store value of node
    Node* next;     // Pointer to next node
    Node* prev;     // Pointer to previous node

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
    Node* head = nullptr; // Points to first node
    Node* tail = nullptr; // Points to last node

    // Function to insert a node at the front
    void insertAtFront(int val) {
        Node* newnode = new Node(val);  // Create new node

        if (head == nullptr) {          // If list is empty
            head = tail = newnode;      // New node is head & tail
            return;
        }

        newnode->next = head;           // New node points to old head
        head->prev = newnode;           // Old head's prev points to new node
        newnode->prev = nullptr;        // New node's prev is null
        head = newnode;                 // Update head to new node
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

    // Insert nodes at front
    dl.insertAtFront(30);  // List: 30
    dl.insertAtFront(20);  // List: 20 -> 30
    dl.insertAtFront(10);  // List: 10 -> 20 -> 30

    cout << "Doubly Linked List: " << endl;
    dl.display();  // Output: 10 -> 20 -> 30 -> null

    return 0;
}
