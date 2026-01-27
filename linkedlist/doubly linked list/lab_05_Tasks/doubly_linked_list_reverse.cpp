#include <iostream>
using namespace std;

// Node class for Doubly Linked List
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    // Insert at back
    void insertAtBack(int val) {
        Node* newnode = new Node(val);
        if (head == nullptr) {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }

    // Reverse the doubly linked list
    void reverseDLL() {
        Node* current = head;
        Node* temp = nullptr;

        // Step 1: Swap next and prev for every node
        while (current != nullptr) {
            temp = current->prev;           // store prev temporarily
            current->prev = current->next;  // swap prev and next
            current->next = temp;           // complete swap
            current = current->prev;        // move to next node (originally next)
        }

        // Step 2: Swap head and tail
        if (temp != nullptr) {
            head = temp->prev;              // new head = old tail
        }
    }
};

// Main function
int main() {
    DoublyLinkedList dl;

    // Insert nodes
    dl.insertAtBack(10);
    dl.insertAtBack(20);
    dl.insertAtBack(30);
    dl.insertAtBack(40);

    cout << "Original DLL:" << endl;
    dl.display();  // 10 <-> 20 <-> 30 <-> 40 <-> null

    // Reverse DLL
    dl.reverseDLL();

    cout << "Reversed DLL:" << endl;
    dl.display();  // 40 <-> 30 <-> 20 <-> 10 <-> null

    return 0;
}
