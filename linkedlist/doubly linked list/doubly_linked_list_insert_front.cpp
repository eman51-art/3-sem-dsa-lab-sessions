#include <iostream>
using namespace std;

// Node class for Doubly Linked List
class Node {
public:
    int data;       // 💾 store value of node
    Node* next;     // ➡️ pointer to next node
    Node* prev;     // ⬅️ pointer to previous node

    // Constructor to create a node with a value
    Node(int val) {
        data = val;
        next = nullptr;  // initially, no next node
        prev = nullptr;  // initially, no previous node
    }
};

// Doubly Linked List class
class doublelinkedlist {
public:
    Node* head = nullptr; // 🟢 points to first node
    Node* tail = nullptr; // 🔴 points to last node

    // Function to insert a node at the front
    void insertAtFront(int val) {
        Node* newnode = new Node(val);  // create new node

        if (head == nullptr) {          // list empty
            head = tail = newnode;      // new node is head & tail
            return;
        }

        newnode->next = head;           // new node points to old head
        head->prev = newnode;           // old head's prev points to new node
        newnode->prev = nullptr;        // new node's prev is null
        head = newnode;                 // update head to new node
    }

    // Function to display the list from head to tail
    void display() {
        Node* temp = head;              // start from head
        while (temp != nullptr) {
            cout << temp->data << " -> "; // print node value
            temp = temp->next;           // move to next node
        }
        cout << "null" << endl;          // end of list
    }
};

int main() {
    doublelinkedlist dl;

    // Insert nodes at front
    dl.insertAtFront(30);  // list: 30
    dl.insertAtFront(20);  // list: 20 -> 30
    dl.insertAtFront(10);  // list: 10 -> 20 -> 30

    cout << "Doubly Linked List: " << endl;
    dl.display();  // Output: 10 -> 20 -> 30 -> null

    return 0;
}
