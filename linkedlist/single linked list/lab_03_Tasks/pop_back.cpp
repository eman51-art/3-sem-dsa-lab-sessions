#include <iostream>
using namespace std;

// Node class represents one element of the linked list
class Node {
public:
    int data;      // store value of node
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

    // Constructor creates empty list
    linkedlist() {
        head = nullptr;
    }

    // Function to insert node at the back (end) of the list
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
        temp->next = newnode;            // attach new node at the end
    }

    // Function to remove the last node (pop back)
    void popBack() {
        if (head == nullptr) return;      // list empty, nothing to remove

        if (head->next == nullptr) {      // only 1 node in the list
            delete head;                  // delete the single node
            head = nullptr;               // list becomes empty
            return;
        }

        Node* temp = head;                // start from head

        // Move temp to second-last node
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        // Now temp->next is last node
        delete temp->next;                // delete last node
        temp->next = nullptr;             // second-last node becomes last
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;                // start from head
        while (temp != nullptr) {         // traverse till end
            cout << temp->data << " ";    // print node value
            temp = temp->next;            // move to next node
        }
        cout << "null" << endl;           // end of list
    }
};

int main() {
    cout << "Linked list example" << endl;
    cout << "Insertion at back and pop back:" << endl;

    linkedlist l;        // create linked list object

    // Insert nodes at the back
    l.insertatback(10);
    l.insertatback(20);
    l.insertatback(30);
    l.insertatback(40);

    // Remove the last node
    l.popBack();

    // Display the linked list
    l.display();         // expected output: 10 20 30 null

    return 0;
}
