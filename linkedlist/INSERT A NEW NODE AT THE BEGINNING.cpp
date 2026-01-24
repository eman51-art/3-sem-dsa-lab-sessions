#include <iostream>
using namespace std;

class Node{
public:
    Node* next;
    Node* prev;
    int data;

    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class doublelinkedlist{
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void insertAtFront(int val){
        Node* newnode = new Node(val);
        if(head == nullptr){
            head = tail = newnode;
            return;
        }
        newnode->next = head;      // newnode ka next = old head
        head->prev = newnode;      // old head ka prev = newnode
        newnode->prev = nullptr;   // newnode ka prev = nullptr
        head = newnode;            // update head
    }

    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

int main() {
    doublelinkedlist dl;

    // Front insertions
    dl.insertAtFront(30);
    dl.insertAtFront(20);
    dl.insertAtFront(10);

    cout << "Doubly Linked List: "<<endl;
    dl.display();  // Output: 10 -> 20 -> 30 -> null

    return 0;
}
