  #include <iostream>
using namespace std;

// Node class represents a single node in the BST
class Node{
public:
    int data;       // Value stored in the node
    Node* left;     // Pointer to left child
    Node* right;    // Pointer to right child

    // Constructor to initialize a node with a value
    Node(int val){
        data = val;
        left = right = nullptr; // Initially, children are NULL
    }
};

// BST class represents the Binary Search Tree
class BST{
public:

    // Insert function to add a new key into the BST
    // Node*& root → reference to root pointer, so original tree can be updated
    void insertion(Node*& root, int key){

        // Base case: if current position is empty, insert new node here
        if(root == nullptr){
            root = new Node(key);
            return;
        }

        // If key is smaller, go to left subtree
        if(key < root->data){
            insertion(root->left, key);
        }
        // If key is greater or equal, go to right subtree
        else{
            insertion(root->right, key);
        }
    }
    
    // Display function: prints tree in preorder (Root → Left → Right)
    void display(Node* root){
        if(root == nullptr){
            return;  // Base case: if node is NULL, do nothing
        }

        cout << root->data << " ";   // Visit the root node
        display(root->left);          // Recursively visit left subtree
        display(root->right);         // Recursively visit right subtree
    }
};

int main(){
    BST b;                 // Create BST object
    Node* root = nullptr;  // Initially tree is empty

    // Insert multiple nodes into the BST
    b.insertion(root, 50); // Root node
    b.insertion(root, 30); // Left child of 50
    b.insertion(root, 70); // Right child of 50
    b.insertion(root, 20); // Left child of 30
    b.insertion(root, 40); // Right child of 30
    b.insertion(root, 60); // Left child of 70
    b.insertion(root, 80); // Right child of 70

    // Display the tree in preorder
    b.display(root);   // Output: 50 30 20 40 70 60 80

    return 0;
}
