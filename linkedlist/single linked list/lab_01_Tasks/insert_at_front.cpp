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

    // Constructor creates empty list
    linkedlist() {
        head = nullptr;
    }

    // Function to insert a new node at the front (beginning) of the list
    void insertatfront(int value) {
        Node* newnode = new Node(value); // create new node
        if (head == nullptr) {           // if list is empty
            head = newnode;              // new node becomes head
            return;
        }
        newnode->next = head;            // new node points to current head
        head = newnode;                  // head now becomes new node
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;               // start from head
        while (temp != nullptr) {        // traverse till end
            cout << temp->data << " ";   // print node value
            temp = temp->next;           // move to next node
        }
        cout << "null" << endl;          // end of list
    }
};

int main() {
    cout << "Linked list example" << endl;
    cout << "Insertion at front:" << endl;

    linkedlist l;       // create a linked list object

    // Insert nodes at the front
    l.insertatfront(30);
    l.insertatfront(20);
    l.insertatfront(10);

    // Display the linked list
    l.display();        // expected output: 10 20 30 null

    return 0;
}
