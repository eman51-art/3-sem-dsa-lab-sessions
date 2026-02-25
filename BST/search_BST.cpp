#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

class BST{
public:

   
    void insertion(Node*& root, int key){

        if(root == nullptr){
            root = new Node(key);
            return;
        }

        if(key < root->data){
            insertion(root->left, key);
        }
        else{
            insertion(root->right, key);
        }
    }
    
  bool search(Node*root,int find){
       if(root==nullptr){
            return false;
        }
        if(root->data==find){
           
           return true;
        }
     
        if(find<root->data){
     return search(root->left,find);}
     
            else{
               return search(root->right,find);
            }
    }
    
    void display(Node*root){
        if(root==nullptr){
            return;
        }
      cout<<root->data<<" ";
      display(root->left);
      display(root->right);
        
    }
};

int main(){
    BST b;
    Node* root = nullptr;

   
    b.insertion(root, 50);
    b.insertion(root, 30);
    b.insertion(root, 70);
    b.insertion(root, 20);
      b.insertion(root, 40);
        b.insertion(root, 60);
          b.insertion(root, 80);
    b.display(root);
  cout<<endl;
   cout<<"search for element:"<<endl;
  
   if(b.search(root,60)){
       cout<<"found ";
   }
   else{
       cout<<"Not found";
   }
    return 0;
}
