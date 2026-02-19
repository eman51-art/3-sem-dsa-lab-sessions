#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next=nullptr;
    Node(int val){
        data=val;
    }
};
class Queue {
public:
   
    Node*head=nullptr;
    Node*tail=nullptr;
   
    // Constructor

    // Enqueue
    void enqueue(int val) {
       Node*newnode=new Node(val) ;
       if(head==nullptr){
           head=tail=newnode;
          
           return;
       }
       tail->next=newnode;
       tail=newnode;
      
    }
    void dequeue() {
       if(head == nullptr) {
    cout << "Queue is empty!" << endl;
    return;
}
Node* temp = head;
head = head->next;
delete temp;
if(head == nullptr) tail = nullptr;
    }
    
   

    // Display
    void display() {
       Node*temp=head;
       while(temp!=nullptr){
           cout<<temp->data<<"->";
           temp=temp->next;
       }
       cout<<"Null"<<endl;
    }
};

int main() {
    Queue q;
   q.enqueue(10);
    q.enqueue(40);
     q.enqueue(50);
     q.display();
    q.dequeue();  // removes front element (10 in this case)

         q.display();
   

    return 0;
}
