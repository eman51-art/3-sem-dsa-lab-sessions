#include <iostream>
using namespace std;

// Node class for singly linked list
class Node {
public:
    int data;      // value stored in the node
    Node* next;    // pointer to next node

    // Constructor to create a node with a value
    Node(int val) {
        data = val;
        next = nullptr; // next is null initially
    }
};

// Singly linked list class
class linkedlist {
public:
    Node* head; // pointer to first node

    // Constructor creates empty list
    linkedlist() {
        head = nullptr;
    }

    // Function to insert a node at the back (end) of the list
    void insertAtBack(int val) {
        Node* newnode = new Node(val); // create new node

        if (head == nullptr) {         // if list is empty
            head = newnode;            // new node becomes head
            return;
        }

        Node* temp = head;             // start from head
        while (temp->next != nullptr) {// traverse to last node
            temp = temp->next;
        }
        temp->next = newnode;          // attach new node at the end
    }

    // Display the linked list
    void display() {
        Node* temp = head;             // start from head
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

int main() {
    linkedlist l; // create linked list object

    // Insert nodes at the back
    l.insertAtBack(10);
    l.insertAtBack(20);
    l.insertAtBack(30);

    cout << "Singly Linked List (Insert at Back):" << endl;
    l.display();  // output: 10 -> 20 -> 30 -> null

    return 0;
}
