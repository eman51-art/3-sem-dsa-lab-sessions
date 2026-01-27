#include <iostream>
using namespace std;

// Node class represents one element of the linked list
class Node {
public:
    int data;      // value stored in the node
    Node* next;    // pointer to next node

    // Constructor to create a node with a value
    Node(int value) {
        data = value;
        next = nullptr; // next is null initially
    }
};

// Linked list class
class linkedlist {
public:
    Node* head; // pointer to first node

    // Constructor creates an empty list
    linkedlist() {
        head = nullptr;
    }

    // Function to insert a new node at the back (end) of the list
    void insertatback(int value) {
        Node* newnode = new Node(value); // create new node
        if (head == nullptr) {           // if list is empty
            head = newnode;              // new node becomes head
            return;
        }

        Node* temp = head;               // start from head
        while (temp->next != nullptr) {  // traverse to last node
            temp = temp->next;
        }
        temp->next = newnode;            // attach new node at end
    }

    // Function to remove the first node of the list (pop front)
    void popfront() {
        if (head == nullptr) return;     // if list is empty, do nothing

        Node* temp = head;               // store current head
        head = head->next;               // move head to next node
        delete temp;                     // delete old head
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;               // start from head
        while (temp != nullptr) {        // traverse till end
            cout << temp->data << " ";   // print data
            temp = temp->next;           // move to next node
        }
        cout << "null" << endl;          // end of list
    }
};

int main() {
    cout << "Linked list example" << endl;
    cout << "Insertion at back and pop front:" << endl;

    linkedlist l;        // create a linked list object

    // Insert nodes at the back
    l.insertatback(30);
    l.insertatback(20);
    l.insertatback(10);

    // Remove the first node
    l.popfront();

    // Display the linked list
    l.display();

    return 0;
}
