#include <iostream>
using namespace std;

class Stack {
    int arr[10];  // array to store stack elements
    int top;      // points to last element
    int n;        // maximum size

public:
    // Constructor
    Stack() {
        top = -1;                     // stack is empty initially
        n = sizeof(arr)/sizeof(arr[0]); // size of array
    }

    // Push operation
    void push(int val) {
        if(top == n - 1) {           // check overflow
            cout << "Overflow" << endl;
            return;
        }
        top++;                        // move top to next empty slot
        arr[top] = val;               // store value
    }

    // Pop operation
    void pop() {
        if(top == -1) {               // check underflow
            cout << "Underflow" << endl;
            return;
        }
        top--;                        // remove top element
    }

    // Display all elements
    void display() {
        if(top == -1) {               // check if stack is empty
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for(int i = 0; i <= top; i++) {  // print from bottom to top
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Peek / top element
    void peekortop() {
        if(top == -1) {               // check if stack is empty
            cout << "Stack is empty" << endl;
        } else {
            cout << "Top element: " << arr[top] << endl;  // show top element
        }
    }
};

int main() {
    Stack st;         // create stack object
    int choice, value;

    while(true) {
        // Interactive menu
        cout << "\nChoose operation:\n";
        cout << "1 → Push\n";
        cout << "2 → Pop\n";
        cout << "3 → Display\n";
        cout << "4 → Peek / Top\n";
        cout << "5 → Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                st.push(value);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                st.display();
                break;
            case 4:
                st.peekortop();
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}
