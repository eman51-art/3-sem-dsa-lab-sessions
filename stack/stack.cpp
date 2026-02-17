#include <iostream>
using namespace std;

class Stack {
    int arr[10];
    int top;
    int n;

public:
    Stack() {
        top = -1;
        n = sizeof(arr)/sizeof(arr[0]);
    }

    void push(int val) {
        if(top == n-1) {
            cout << "Overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop() {
        if(top == -1) {
            cout << "Underflow" << endl;
            return;
        }
        top--;
    }

    void display() {
        if(top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for(int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack st;
    int choice, value;

    while(true) {
        // Menu
        cout << "\nChoose operation:\n";
        cout << "1 → Push\n";
        cout << "2 → Pop\n";
        cout << "3 → Display\n";
        cout << "4 → Exit\n";
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
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}
