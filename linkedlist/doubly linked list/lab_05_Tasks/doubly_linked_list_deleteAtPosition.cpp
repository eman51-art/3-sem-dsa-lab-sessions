#include <iostream>
using namespace std;

// Node class
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

// Doubly Linked List
class DoublyLinkedList {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    // Insert at back
    void insertAtBack(int value) {
        Node* newnode = new Node(value);
        if (!head) {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    // Delete at position (first, middle, last)
    void deleteAtPosition(int pos) {
        if (!head) return; // empty list

        // Delete first node
        if (pos == 1) {
            Node* removes = head;
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr; // list became empty
            delete removes;
            return;
        }

        // Traverse to pos-1 node
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (!temp || !temp->next) return; // invalid pos

        Node* removes = temp->next; // node to delete

        // Update links
        temp->next = removes->next;
        if (removes->next) {
            removes->next->prev = temp; // middle node
        } else {
            tail = temp; // last node deleted
        }

        delete removes; // free memory
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
};

// Main function
int main() {
    DoublyLinkedList dl;

    // Insert at back
    dl.insertAtBack(10);
    dl.insertAtBack(20);
    dl.insertAtBack(30);
    dl.insertAtBack(40);
    dl.insertAtBack(50);

    cout << "Original List: ";
    dl.display();

    // Delete examples
    dl.deleteAtPosition(1); // delete front
    dl.deleteAtPosition(3); // delete middle
    dl.deleteAtPosition(3); // delete last

    cout << "After Deletions: ";
    dl.display();

    return 0;
}
