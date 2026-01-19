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
    void insertatfront(int value){
        Node* newnode=new Node(value);
        if(head==nullptr){
            head=newnode;
            return;
        }
        newnode->next=head;
        head=newnode;
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
   l.insertatfront(30);
   l. insertatfront(20);
    l.insertatfront(10);
    l.display();

    return 0;
}
