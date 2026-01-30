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

    // Insert node at the back
    void insertAtBack(int val) {
        Node* newnode = new Node(val);
        if (!head) {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    // Merge another list into this list
    void merge(DoublyLinkedList &other) {
        if (!head) {  // this list empty
            head = other.head;
            tail = other.tail;
            return;
        }
        if (!other.head) return;  // other list empty

        tail->next = other.head;
        other.head->prev = tail;
        tail = other.tail;
    }

    // Sort the list using simple bubble sort (swap values)
    void sort() {
        if (!head) return;

        Node* temp;
        Node* move;

        for(temp = head; temp != nullptr; temp = temp->next) {
            for(move = temp->next; move != nullptr; move = move->next) {
                if(temp->data > move->data) {
                    int t = temp->data;
                    temp->data = move->data;
                    move->data = t;
                }
            }
        }
    }

    // Display the list
    void display() {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data;
            if(temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << " -> nullptr" << endl;
    }
};

int main() {
    DoublyLinkedList list1, list2;

    // Insert nodes in first list
    list1.insertAtBack(10);
    list1.insertAtBack(20);
    list1.insertAtBack(4);

    // Insert nodes in second list
    list2.insertAtBack(6);
    list2.insertAtBack(7);
    list2.insertAtBack(8);

    cout << "List 1: ";
    list1.display();
    cout << "List 2: ";
    list2.display();

    // Merge lists
    list1.merge(list2);
    cout << "After Merge: ";
    list1.display();

    // Sort merged list
    list1.sort();
    cout << "After Sort: ";
    list1.display();

    return 0;
}
