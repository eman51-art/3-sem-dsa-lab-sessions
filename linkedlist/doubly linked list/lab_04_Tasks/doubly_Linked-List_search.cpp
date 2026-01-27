#include <iostream>
using namespace std;

// Node class for Doubly Linked List
class Node {
public:
    int data;       // Store the value of the node
    Node* next;     // Pointer to the next node
    Node* prev;     // Pointer to the previous node

    // Constructor to initialize a node with a value
    Node(int val) {
        data = val;
        next = nullptr;  // No next node initially
        prev = nullptr;  // No previous node initially
    }
};

// Doubly Linked List class
class doublelinkedlist {
public:
    Node* head = nullptr; // Pointer to first node
    Node* tail = nullptr; // Pointer to last node

    // Insert a node at the back (end) of the list
    void insertAtBack(int val) {
        Node* newnode = new Node(val);  // Create new node

        if(head == nullptr) {           // If list is empty
            head = tail = newnode;      // New node is both head and tail
            return;
        }

        tail->next = newnode;           // Old tail's next points to new node
        newnode->prev = tail;           // New node's prev points to old tail
        tail = newnode;                 // Update tail to new node
    }

    // Search for a value in the list
    void search(int x) {
        Node* temp = head;              // Start from head
        while(temp != nullptr) {
            if(temp->data == x) {       // Value found
                cout << "Value found" << endl;
                return;
            }
            temp = temp->next;          // Move to next node
        }
        cout << "Not found" << endl;    // Value not in list
    }

    // Display the list from head to tail
    void display() {
        Node* temp = head;              // Start from head
        while(temp != nullptr) {
            cout << temp->data << " -> "; // Print node value
            temp = temp->next;            // Move to next node
        }
        cout << "null" << endl;          // End of list
    }
};

int main() {
    doublelinkedlist dl;

    // Insert nodes at back
    dl.insertAtBack(10);
    dl.insertAtBack(20);
    dl.insertAtBack(30);
    dl.insertAtBack(40);

    cout << "Doubly Linked List: " << endl;
    dl.display();       // Output: 10 -> 20 -> 30 -> 40 -> null
    dl.search(40);      // Output: Value found
    dl.search(50);      // Output: Not found

    return 0;
}
