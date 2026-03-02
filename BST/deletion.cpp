#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Solution class with BST delete
class Solution {
public:
    // Helper to find minimum value node in a subtree
    Node* findMin(Node* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    Node* delNode(Node* root, int x) {
        if (root == NULL)
            return NULL;

        // Search phase
        if (x < root->data) {
            root->left = delNode(root->left, x);
        }
        else if (x > root->data) {
            root->right = delNode(root->right, x);
        }
        else {
            // Case 1: No child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: One child
            else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            else {
                Node* successor = findMin(root->right);
                root->data = successor->data;
                root->right = delNode(root->right, successor->data);
            }
        }

        return root;
    }
};

// Helper function to print inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Main function
int main() {
    // Create tree manually
    Node* root = new Node(25);
    root->left = new Node(15);
    root->right = new Node(35);
    root->right->left = new Node(30);
    root->right->right = new Node(40);

    cout << "Original BST (Inorder): ";
    inorder(root);
    cout << endl;

    Solution sol;
    int key = 35;
    root = sol.delNode(root, key);

    cout << "BST after deleting " << key << " (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
