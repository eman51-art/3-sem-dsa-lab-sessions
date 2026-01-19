#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int value){
        data=value;
        next=nullptr;
    }
};

class linkedlist{
    public:
    Node* head;
    linkedlist(){
        head=nullptr;
    }
    void insertatback(int value){
        Node* newnode=new Node(value);
        if(head==nullptr){
            head=newnode;
            return;
        }
       Node* temp=head;
       while(temp->next!=nullptr){
           temp=temp->next;
       }
       temp->next=newnode;
    }
  
   
  void popBack() {
    if(head == nullptr) return;      // List empty

    if(head->next == nullptr) {      // Only 1 node
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    // Move temp to second-last node
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }

    // Now temp->next is last node
    delete temp->next;                // Delete last node
    temp->next = nullptr;             // Second last node now becomes last
}

   
    
    void display(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"null";
    }
    
    
};
int main() {
    // Write C++ code here
   cout << "linked list"<<endl;
   cout<<"insertion at front"<<endl;
   linkedlist l;
   l.insertatback(10);
   l.insertatback(20);
    l.insertatback(30);
     l.insertatback(40);
    l.popBack();
    l.display();
    
    return 0;
}
