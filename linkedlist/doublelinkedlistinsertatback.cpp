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

    void insertAtBack(int val){
        Node* newnode = new Node(val);

        if(head == nullptr){
            head = tail = newnode;
            return;
        }

        tail->next = newnode;     // old tail ka next = new node
        newnode->prev = tail;     // new node ka prev = old tail
        tail = newnode;           // update tail
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

    dl.insertAtBack(10);
    dl.insertAtBack(20);
    dl.insertAtBack(30);

    cout << "Doubly Linked List: " << endl;
    dl.display();   // 10 -> 20 -> 30 -> null

    return 0;
}
