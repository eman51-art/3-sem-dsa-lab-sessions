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

// Doubly Linked List class
class DoublyLinkedList {
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Insert at position (front = 1)
    void insertAtPosition(int val, int pos) {
        Node* newNode = new Node(val);
        if (pos == 1) { // insert front
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            if (!tail) tail = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (!temp || !temp->next) { // insert at end
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else { // insert middle
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    // Delete at position
    void deleteAtPosition(int pos) {
        if (!head) return; // empty list

        if (pos == 1) { // front
            Node* removes = head;
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr; // list became empty
            delete removes;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (!temp || !temp->next) return; // invalid pos

        Node* removes = temp->next; // node to delete
        temp->next = removes->next;
        if (removes->next)
            removes->next->prev = temp; // middle node
        else
            tail = temp; // last node deleted

        delete removes;
    }

    // Reverse DLL
    void reverse() {
        Node* temp = nullptr;
        Node* current = head;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr)
            head = temp->prev;
    }

    // Merge another list
    void merge(DoublyLinkedList &other) {
        if (!head) { head = other.head; tail = other.tail; return; }
        if (!other.head) return;

        tail->next = other.head;
        other.head->prev = tail;
        tail = other.tail;
    }

    // Sort list (ascending)
    void sort() {
        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            for (Node* move = temp->next; move != nullptr; move = move->next) {
                if (temp->data > move->data) {
                    int t = temp->data;
                    temp->data = move->data;
                    move->data = t;
                }
            }
        }
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main
int main() {
    DoublyLinkedList list1, list2;
    int choice, val, pos;

    do {
        cout << "\n1.Insert at End\n2.Insert at Position\n3.Delete at Position\n4.Reverse\n5.Merge List 2 into List 1\n6.Sort List 1\n7.Display List 1\n8.Exit\n";
        cout << "Enter choice: "; cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert at end: "; cin >> val;
                list1.insertAtEnd(val);
                break;

            case 2:
                cout << "Enter value and position to insert: "; cin >> val >> pos;
                list1.insertAtPosition(val, pos);
                break;

            case 3:
                cout << "Enter position to delete: "; cin >> pos;
                list1.deleteAtPosition(pos);
                break;

            case 4:
                list1.reverse();
                cout << "List reversed.\n";
                break;

            case 5:
                cout << "Creating List 2 for merge.\n";
                int n, v;
                cout << "Enter number of nodes in List 2: "; cin >> n;
                for(int i=0; i<n; i++){
                    cout << "Enter value: "; cin >> v;
                    list2.insertAtEnd(v);
                }
                list1.merge(list2);
                cout << "List 2 merged into List 1.\n";
                break;

            case 6:
                list1.sort();
                cout << "List 1 sorted.\n";
                break;

            case 7:
                cout << "List 1: ";
                list1.display();
                break;

            case 8:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 8);

    return 0;
}
