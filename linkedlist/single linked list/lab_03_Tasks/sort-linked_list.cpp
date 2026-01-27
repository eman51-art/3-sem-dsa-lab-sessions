#include <iostream>
using namespace std;

// Node class represents each element/node in the linked list
class Node {
public:
    int data;     // value stored in the node
    Node* next;   // pointer to the next node

    // Constructor to initialize a node with a value
    Node(int value) {
        data = value;
        next = nullptr; // initially, next is NULL
    }
};

// LinkedList class manages the entire linked list
class linkedlist {
    int count = 0; // keeps track of number of nodes in the list

public:
    Node* head; // pointer to the first node (head)

    // Constructor initializes an empty list
    linkedlist() {
        head = nullptr;
    }

    // Function to insert a node at the end of the list
    void insertatback(int value) {
        Node* newnode = new Node(value); // create new node
        if (head == nullptr) {           // if list is empty
            head = newnode;              // new node becomes the head
            count++;
            return;
        }
        Node* temp = head;               // traverse the list
        while (temp->next != nullptr) {  // go to last node
            temp = temp->next;
        }
        temp->next = newnode;            // attach new node at the end
        count++;
    }

    // Function to sort linked list in ascending order
    void sortascending() {
        for (int i = 0; i < count; i++) {
            Node* curr = head;       // start from first node
            Node* ptr = curr->next;  // next node
            while (ptr != nullptr) { // traverse till end
                if (curr->data > ptr->data) { // if current > next
                    int swap = curr->data;    // swap their data
                    curr->data = ptr->data;
                    ptr->data = swap;
                }
                curr = curr->next; // move current
                ptr = ptr->next;   // move next
            }
        }
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;              // start from head
        while (temp != nullptr) {       // traverse till end
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;         // end of list
        cout << "The count of nodes is: " << count << endl;
    }
};

int main() {
    linkedlist l; // create a linked list object

    // Insert nodes at the back
    l.insertatback(20);
    l.insertatback(10);
    l.insertatback(40);
    l.insertatback(30);

    cout << "Linked list before sort:" << endl;
    l.display(); // display unsorted list

    l.sortascending(); // sort the list in ascending order

    cout << "Linked list after sort:" << endl;
    l.display(); // display sorted list

    return 0;
}
