📝 Singly Linked List (SLL) 

A linked list is a linear data structure where nodes are not stored in contiguous memory.

Each node contains:

💾 Data → value of the node

➡️ Next → pointer to the next node

2️⃣ Node Structure (C++ Code)
class Node {
public:
    int data;    // 💾 store value
    Node* next;  // ➡️ pointer to next node

    Node(int val) { // constructor
        data = val;
        next = nullptr;
    }
};

3️⃣ Linked List Structure

Head 🟢 → points to first node

Tail 🔴 → points to last node (optional)

class linkedlist {
public:
    Node* head;
    linkedlist() { head = nullptr; }
};

4️⃣ Basic Operations
🔹 a) Insert at Front ⬆️

Steps:

Create new node 🆕

New node ➡️ current head

Head = new node 🟢

void insertAtFront(int val) {
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

🔹 b) Insert at Back ⬇️

Steps:

Create new node 🆕

If empty → head = new node 🟢

Else traverse to last node

Last node ➡️ new node

void insertAtBack(int val) {
    Node* newnode = new Node(val);
    if(head == nullptr) { head = newnode; return; }
    Node* temp = head;
    while(temp->next != nullptr) temp = temp->next;
    temp->next = newnode;
}

🔹 c) Delete from Front 🧹
void popFront() {
    if(head == nullptr) return;       // empty list ❌
    Node* temp = head;
    head = head->next;                // move head
    delete temp;                      // delete old node
}

🔹 d) Delete from Back 🧹
void popBack() {
    if(head == nullptr) return;        // empty list ❌
    if(head->next == nullptr) { delete head; head = nullptr; return; } // 1 node
    Node* temp = head;
    while(temp->next->next != nullptr) temp = temp->next; // move to 2nd last
    delete temp->next;                 // delete last
    temp->next = nullptr;              // update tail
}

5️⃣ Display / Traverse 👀
void display() {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}

6️⃣ Count Nodes 🔢

Using variable count or dynamic traversal:

int countNodes() {
    int c = 0;
    Node* temp = head;
    while(temp != nullptr) { c++; temp = temp->next; }
    return c;
}

7️⃣ Advantages ✅

Dynamic size 🌀

Easy insertion/deletion at front/back ✨

Efficient memory for frequent insertions/deletions 💡

8️⃣ Disadvantages ❌

Accessing nth node → O(n) ⏱️

Extra memory for next pointer 🧠

No backward traversal ↩️

9️⃣ Time Complexity ⏱️
Operation	Best Case	Worst Case
Insert at Front ⬆️	O(1)	O(1)
Insert at Back ⬇️	O(1)*	O(n)
Delete from Front 🧹	O(1)	O(1)
Delete from Back 🧹	O(1)*	O(n)
Search 🔍	O(1)	O(n)




🔟 Visual Representation 👁️
Head 🟢 -> [10 | ➡️] -> [20 | ➡️] -> [30 | ➡️] -> null
