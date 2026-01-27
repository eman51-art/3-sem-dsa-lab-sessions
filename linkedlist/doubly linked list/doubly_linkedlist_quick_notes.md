Doubly Linked List (DLL) – Quick Notes

Definition:

A Doubly Linked List is a sequence of nodes where each node contains:

💾 Data → stores the value

➡️ Next pointer → points to the next node

⬅️ Prev pointer → points to the previous node

Allows traversal in both directions 🔄 unlike singly linked lists.

Node Structure:
⬅️ prev | 💾 data | ➡️ next


Head’s prev = NULL

Tail’s next = NULL

Advantages of DLL: ✅

🔄 Can traverse forward and backward easily

➕ Easy insertion/deletion at front, back, or middle

💻 Useful in undo/redo operations, browser history, and LRU cache

🏃‍♂️ Efficient for bi-directional movement

Can delete a node given a pointer directly (without head traversal)

Disadvantages of DLL: ❌

💾 More memory needed per node (extra prev pointer)

⚡ Slightly slower than singly linked list for simple operations

🔄 Pointer management is tricky → more chances of bugs

🛠️ Insertion/deletion requires updating two pointers (next and prev)

Basic Operations:

🟢 Insert at front → Add node at beginning

🔵 Insert at back → Add node at end

🟠 Insert at position → Add node anywhere

❌ Delete front/back/position → Remove node

🔍 Search → Find a node with a value

🔢 Count nodes → Total nodes in list

Traversal:

Forward: Head → Tail ➡️

Backward: Tail → Head ⬅️

