#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class linkedlist{
    int count = 0;
public:
    Node* head;
    linkedlist(){
        head = nullptr;
    }

    void insertatback(int value){
        Node* newnode = new Node(value);
        if(head == nullptr){
            head = newnode;
            count++;
            return;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newnode;
        count++;
    }

    void sortascending(){
        for(int i = 0; i < count; i++){
            Node* curr = head;
            Node* ptr = curr->next;
            while(ptr != nullptr){
                if(curr->data > ptr->data){
                    int swap = curr->data;
                    curr->data = ptr->data;
                    ptr->data = swap;
                }
                curr = curr->next;
                ptr = ptr->next;
            }
        }
    }

    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "null" << endl;
        cout << "The count of nodes is: " << count << endl;
    }
};

int main() {
    linkedlist l;
    l.insertatback(20);
    l.insertatback(10);
    l.insertatback(40);
    l.insertatback(30);

    cout << "Linked list before sort:" << endl;
    l.display();

    l.sortascending();

    cout << "Linked list after sort:" << endl;
    l.display();

    return 0;
}
