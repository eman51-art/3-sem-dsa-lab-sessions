#include <iostream>
using namespace std;

class Queue {
public:
    int front;
    int rear;
    int arr[4];
    int size;

    // Constructor
    Queue() {
        front = -1;
        rear = -1;
        size = sizeof(arr)/sizeof(arr[0]);
    }

    // Enqueue
    void enqueue(int val) {
        if (rear == size - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) front = 0; // first element
        rear++;
        arr[rear] = val;
        cout << val << " enqueued" << endl;
    }

    // Dequeue
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        
            cout << arr[front] << " dequeued" << endl;
        front++; // m 
        
      
        if (front > rear) { // reset when queue empty
            front = rear = -1;
        }
    }

    // Display
    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice; int val; 
   
    while (true) {
        cout << "\nEnter your choice: 1-Enqueue 2-Dequeue 3-Display -1-Exit: ";
        cin >> choice;

        if (choice == -1) break;

        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;   // <--- Important
            case 2:
          
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            default:
                cout << "Incorrect choice!" << endl;
        }
    }

    return 0;
}

