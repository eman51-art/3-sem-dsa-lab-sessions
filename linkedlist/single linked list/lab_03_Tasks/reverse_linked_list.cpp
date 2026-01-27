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
    Node* head;     // pointer to first node

    // Constructor creates empty list
    linkedlist() {
        head = nullptr;
    }

    // Function to insert node at the back (end)
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

    // Function to reverse the linked list
    void reverselist() {
        Node* reverse = nullptr;   // will become new head
        Node* current = head;      // start from head

        while (current != nullptr) {        // traverse entire list
            Node* nextnode = current->next; // store next node
            current->next = reverse;        // reverse current node's pointer
            reverse = current;              // move reverse pointer to current
            current = nextnode;             // move to next node
        }

        head = reverse;  // new head of the reversed list
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;                  // start from head
        while (temp != nullptr) {           // traverse list
            cout << temp->data << "-> ";    // print data
            temp = temp->next;              // move to next node
        }
        cout << "null" << endl;             // end of list
    }
};

int main() {
    cout << "Linked List Example" << endl;

    linkedlist l; // create linked list object

    cout << "Insertion at back:" << endl;
    l.insertatback(10);
    l.insertatback(20);
    l.insertatback(30);
    l.insertatback(40);

    cout << "Original list:" << endl;
    l.display();  // display list

    cout << "List after reverse:" << endl;
    l.reverselist();  // reverse list
    l.display();      // display reversed list

    return 0;
}
