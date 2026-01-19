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
    int count;
    public:
    Node* head;
    linkedlist(){
        head=nullptr;
       count=0;
    }
    void insertatback(int value){
        Node* newnode=new Node(value);
        if(head==nullptr){
            head=newnode;
            count++;
            return;
        }
       Node* temp=head;
       while(temp->next!=nullptr){
           temp=temp->next;
       }
         count++;
       temp->next=newnode;
     
    }
    
    void display(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
         
        }
        cout<<"null"<<endl;
        cout<<"count of nodes:"<<count;
    }
};
int main() {
  
   cout << "linked list"<<endl;
   cout<<"insertion at front"<<endl;
   linkedlist l;
   l.insertatback(30);
   l.insertatback(20);
    l.insertatback(10);
    l.display();

    return 0;
}
