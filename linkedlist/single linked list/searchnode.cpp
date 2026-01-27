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
    int count = 0;  // count of nodes in the list

public:
    Node* head;     // pointer to first node

    // Constructor to create empty list
    linkedlist() {
        head = nullptr;
    }

    // Function to insert a new node at the end
    void insertatback(int value) {
        Node* newnode = new Node(value); // create new node
        if (head == nullptr) {           // if list is empty
            head = newnode;              // new node becomes head
        } else {                          // if list has nodes
            Node* temp = head;           // start from head
            while (temp->next != nullptr) { // go to last node
                temp = temp->next;
            }
            temp->next = newnode;        // attach new node at end
        }
        count++;                          // increase node count
    }

    // Function to display all nodes
    void display() {
        Node* temp = head;                // start from head
        cout << "List display: ";
        while (temp != nullptr) {         // traverse till end
            cout << temp->data << " ";    // print node value
            temp = temp->next;            // move to next node
        }
        cout << "NULL" << endl;           // end of list
    }

    // Function to search a value in the list
    void searchnode(int findvalue) {
        Node* temp = head;                // start from head
        int index = 0;                    

        if (head == nullptr) {            // if list empty
            cout << "The list is empty." << endl;
            return;
        }

        while (temp != nullptr) {         // traverse list
            if (temp->data == findvalue) { // if value found
                cout << "Value " << findvalue << " found at index " << index << endl;
                return;
            }
            temp = temp->next;            // move to next node
            index++;                       // increment index
        }

        // if value not found
        cout << "Value " << findvalue << " not found in the list." << endl;
    }
};

int main() {
    linkedlist l;        // create a linked list

    // insert nodes
    l.insertatback(10);
    l.insertatback(20);
    l.insertatback(30);

    // display list
    l.display();

    // search nodes
    l.searchnode(10); // value exists
    l.searchnode(40); // value does not exist

    return 0;
}
