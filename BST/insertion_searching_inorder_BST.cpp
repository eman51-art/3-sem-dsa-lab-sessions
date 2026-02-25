#include <iostream>
using namespace std;

// Node class represents each node in the BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// BST class contains insertion, search, and traversal functions
class BST {
public:

    // Insert a key into BST
    void insertion(Node*& root, int key) {
        if (root == nullptr) {
            root = new Node(key);
            return;
        }

        if (key < root->data) {
            insertion(root->left, key);
        }
        else {
            insertion(root->right, key);
        }
    }

    // Search for a value in BST; returns true if found, false otherwise
    bool search(Node* root, int key) {
        if (root == nullptr) return false;        // Base case: empty subtree

        if (root->data == key) return true;      // Found the key

        if (key < root->data) return search(root->left, key);   // Go left
        else return search(root->right, key);                   // Go right
    }

    // Inorder traversal (prints nodes in sorted order)
    void inorder(Node* root) {
        if (root == nullptr) return;

        inorder(root->left);            // Visit left subtree
        cout << root->data << " ";      // Visit root
        inorder(root->right);           // Visit right subtree
    }
};

int main() {
    BST b;
    Node* root = nullptr;

    //  Insert elements into BST
    b.insertion(root, 50);
    b.insertion(root, 30);
    b.insertion(root, 70);
    b.insertion(root, 20);
    b.insertion(root, 40);
    b.insertion(root, 60);
    b.insertion(root, 80);
   
    // Search for a given value
    int valueToSearch = 60;
    cout << "Searching for " << valueToSearch << ""<<endl;
    if (b.search(root, valueToSearch)) cout << "Found "<< valueToSearch << ""<<endl;
    else cout << valueToSearch << " Not Found"<<endl;

     //Print Inorder traversal (sorted order)
    cout << "Inorder Traversal (Sorted Order): "<<endl;
    b.inorder(root);
  

    return 0;
}
