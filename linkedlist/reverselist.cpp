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
  
   
 
   void reverselist(){
       Node* reverse=nullptr;
       Node* current=head;
       while(current!=nullptr){
           Node* nextnode=current->next;
           current->next=reverse;
           reverse=current;
           current=nextnode;
       }
       head=reverse;
       
   }
    
    void display(){
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<"-> ";
            temp=temp->next;
        }
        cout<<"null"<<endl;
    }
    
    
};
int main() {
    // Write C++ code here
   cout << "linked list"<<endl;
   cout<<"insertion at back"<<endl;
   linkedlist l;
   l.insertatback(10);
   l.insertatback(20);
    l.insertatback(30);
     l.insertatback(40);
    l.display();
    
    cout<<"list after reverse"<<endl;
    l.reverselist();
       l.display();
    
    return 0;
}
