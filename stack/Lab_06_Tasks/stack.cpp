#include <iostream>
using namespace std;

// Stack class using array
class Stack {
    int arr[10];  // array to store stack elements
    int top;      // points to the last element
    int n;        // maximum size of stack

public:
    // Constructor
    Stack() {
        top = -1;                   // stack is empty initially
        n = sizeof(arr) / sizeof(arr[0]); // size of the array
    }

    // Push function
    void push(int val) {
        if(top == n - 1) {          // check overflow
            cout << "Overflow" << endl;
            return;
        }
        top++;                       // move top to next empty slot
        arr[top] = val;              // store value
    }

    // Pop function
    void pop() {
        if(top == -1) {              // check underflow
            cout << "Underflow" << endl;
            return;
        }
        top--;                       // remove top element
    }

    // Display function
    void display() {
        if(top == -1) {              // check if stack is empty
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for(int i = 0; i <= top; i++) {  // print all elements from bottom to top
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack st;              // create stack object
    int input;

    cout << "Enter numbers to push into stack (-1 to stop):" << endl;

    // Input loop
    while(true) {
        cout << "Enter value: ";
        cin >> input;

        if(input == -1) {  // stop condition
            break;
        }
        st.push(input);     // push value into stack
    }

    // Pop and display operations
    st.pop();               // remove top element
    st.display();           // show stack

    st.pop();               // remove top element
    st.display();           // show stack

    return 0;               // end program
}
