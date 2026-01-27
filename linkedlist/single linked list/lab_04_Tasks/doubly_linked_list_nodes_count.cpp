#include <iostream>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int data;       // Data stored in node
    Node* next;     // Pointer to next node
    Node* prev;     // Pointer to previous node

    // Constructor to initialize a node
    Node(int val) {
        data = val;
        next = nullptr; // No next node initially
        prev = nullptr; // No previous node initially
    }
};

// Doubly Linked List class
class doublelinkedlist {
public:
    Node* head = nullptr;   // Points to first node
    Node* tail = nullptr;   // Points to last node

    // Insert a new node at the back of the list
    void insertAtBack(int val) {
        Node* newnode = new Node(val);

        // If list is empty
        if (head == nullptr) {
            head = tail = newnode;
            return;
        }

        // Link new node at the end
        tail->next = newnode;   // Old tail points to new node
        newnode->prev = tail;   // New node prev points to old tail
        tail = newnode;         // Update tail to new node
    }

    // Count total number of nodes in the list
    int countnodes() {
        Node* temp = head;      // Start from head
        int count = 0;
        while (temp != nullptr) {
            count++;            // Increment for each node
            temp = temp->next;  // Move to next node
        }
        return count;           // Return total count
    }

    // Display the list from head to tail
    void display() {
        Node* temp = head;      // Start from head
        while (temp != nullptr) {
            cout << temp->data << " -> "; // Print current node
            temp = temp->next;            // Move forward
        }
        cout << "null" << endl;           // End of list
    }
};

int main() {
    doublelinkedlist dl;

    // Insert nodes at the back
    dl.insertAtBack(10);
    dl.insertAtBack(20);
    dl.insertAtBack(30);
    dl.insertAtBack(40);

    // Display list
    cout << "Doubly Linked List: " << endl;
    dl.display();   // Output: 10 -> 20 -> 30 -> 40 -> null

    // Count nodes
    cout << "Total nodes in DLL: " << dl.countnodes() << endl;

    return 0;
}
