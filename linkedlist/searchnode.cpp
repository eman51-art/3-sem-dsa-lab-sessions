#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class linkedlist {
    int count = 0;
public:
    Node* head;
    linkedlist() {
        head = nullptr;
    }

    void insertatback(int value) {
        Node* newnode = new Node(value);
        if (head == nullptr) {
            head = newnode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        count++;
    }

    void display() {
        Node* temp = head;
        cout << "List display: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void searchnode(int findvalue) {
        Node* temp = head;
        int index = 0;

        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        while (temp != nullptr) {
            if (temp->data == findvalue) {
                cout << "Value " << findvalue << " found at index " << index << endl;
                return;
            }
            temp = temp->next;
            index++;
        }

        cout << "Value " << findvalue << " not found in the list." << endl;
    }
};

int main() {
    linkedlist l;
    l.insertatback(10);
    l.insertatback(20);
    l.insertatback(30);

    l.display();

    l.searchnode(10); // found
    l.searchnode(40); // not found

    return 0;
}
