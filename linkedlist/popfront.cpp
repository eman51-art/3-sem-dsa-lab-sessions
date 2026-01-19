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
    void popfront(){
    if(head == NULL) return;    // List empty

    Node* temp = head;          // point to first node
    head = head->next;          // head ko next par le jayo
    delete temp;                // purana head delete
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
   l.insertatback(30);
   l.insertatback(20);
    l.insertatback(10);
    l.popfront();
    l.display();
    
    return 0;
}
