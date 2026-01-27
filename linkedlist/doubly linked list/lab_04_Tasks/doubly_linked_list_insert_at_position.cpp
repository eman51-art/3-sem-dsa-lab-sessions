#include <iostream>
using namespace std;

// Node class for Doubly Linked List
class Node {
public:
    int data;       // Data stored in node
    Node* next;     // Pointer to next node
    Node* prev;     // Pointer to previous node

    // Constructor to initialize node
    Node(int val) {
        data = val;
        next = nullptr; // No next node initially
        prev = nullptr; // No previous node initially
    }
};

// Doubly Linked List class
class DoublyLinkedList {
public:
    Node* head = nullptr;  // Points to first node
    Node* tail = nullptr;  // Points to last node

    // Insert a node at a given position
    void insertAtPosition(int value, int pos) {
        Node* newnode = new Node(value);

        // Case 1: empty list and position 1
        if (head == nullptr && pos == 1) {
            head = tail = newnode;
            return;
        }

        // Case 2: insert at front
        if (pos == 1) {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
            return;
        }

        // Traverse to position-1
        Node* temp = head;
        int count = 1;
        while (count < pos - 1 && temp->next != nullptr) {
            temp = temp->next;
            count++;
        }

        // Case 3: insert at last (if position exceeds current length)
        if (temp->next == nullptr) {
            temp->next = newnode;
            newnode->prev = temp;
            tail = newnode;
        }
        // Case 4: insert in middle
        else {
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next->prev = newnode;
            temp->next = newnode;
        }
    }

    // Display list from head to tail
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> "; // Show links visually
            temp = temp->next;
        }
        cout << "null" << endl;          // End of list
    }
};

// Main function to test
int main() {
    DoublyLinkedList dl;

    dl.insertAtPosition(10, 1); // insert at front
    dl.insertAtPosition(20, 2); // insert at end
    dl.insertAtPosition(15, 2); // insert in middle
    dl.insertAtPosition(5, 1);  // insert at front
    dl.insertAtPosition(25, 5); // insert at last

    cout << "Doubly Linked List:\n";
    dl.display();  // Display full list

    return 0;
}
