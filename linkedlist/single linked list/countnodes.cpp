#include <iostream>
using namespace std;

// Node class for singly linked list
class Node {
public:
    int data;      // value stored in node
    Node* next;    // pointer to next node

    // Constructor to create a node with a value
    Node(int value) {
        data = value;
        next = nullptr; // next is null initially
    }
};

// Singly linked list class
class linkedlist {
    int count;     // keeps track of number of nodes

public:
    Node* head;    // pointer to first node

    // Constructor creates an empty list
    linkedlist() {
        head = nullptr;
        count = 0;
    }

    // Function to insert a node at the back (end)
    void insertatback(int value) {
        Node* newnode = new Node(value); // create new node

        if (head == nullptr) {           // if list is empty
            head = newnode;              // new node becomes head
            count++;                      // increment node count
            return;
        }

        Node* temp = head;               // start from head
        while (temp->next != nullptr) {  // traverse to last node
            temp = temp->next;
        }

        temp->next = newnode;            // attach new node at end
        count++;                         // increment node count
    }

    // Function to display linked list and node count
    void display() {
        Node* temp = head;               // start from head
        while (temp != nullptr) {        // traverse list
            cout << temp->data << " ";   // print node value
            temp = temp->next;           // move to next node
        }
        cout << "null" << endl;          // end of list
        cout << "Count of nodes: " << count << endl; // display node count
    }

    // Function to get count of nodes
    int getCount() {
        return count;
    }
};

int main() {
    cout << "Singly Linked List Example" << endl;
    cout << "Insertion at Back:" << endl;

    linkedlist l;   // create linked list object

    // Insert nodes at back
    l.insertatback(30);
    l.insertatback(20);
    l.insertatback(10);

    // Display linked list and count
    l.display();    // expected output: 30 20 10 null, count: 3

    // Access node count using function
    cout << "Node count using getCount(): " << l.getCount() << endl;

    return 0;
}
