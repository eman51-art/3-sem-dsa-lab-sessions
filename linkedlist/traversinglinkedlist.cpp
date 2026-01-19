#include <iostream>
using namespace std;

// struct ka default access public hota hai, aur class ka default access private hota hai.
struct Node {
    int data;
    Node* next;
};

// Function to insert at the end
void insertend(Node*& start, int value) {
    Node* newnode = new Node(); // dynamically allocate memory
    newnode->data = value;
    newnode->next = nullptr;

    if (start == nullptr) {  // list empty
        start = newnode;
        return;
    }

    Node* temp = start;
    while (temp->next != nullptr) {  // go to last node
        temp = temp->next;
    }
    temp->next = newnode;
}

// Function to traverse the linked list
void traversing(Node* start) {
    Node* temp = start;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    cout << "Linked list:" << endl;

    Node* start = nullptr;

    insertend(start, 10);
    insertend(start, 20);
    insertend(start, 30);

    traversing(start);

    return 0;
}
