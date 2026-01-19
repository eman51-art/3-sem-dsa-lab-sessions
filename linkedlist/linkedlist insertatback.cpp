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
    l.display();

    return 0;
}
