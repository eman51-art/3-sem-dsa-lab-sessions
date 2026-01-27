📝 Singly Linked List  – Notes

1️⃣ Definition

A singly linked list is a linear data structure where each element (node) points to the next.

Nodes are not stored in contiguous memory (unlike arrays).

Each node has:

Data 💾 → stores the value

Next ➡️ → pointer to the next node

2️⃣ Key Components

Node → basic building block (contains data + next pointer)

Head 🟢 → first node of the list

Tail 🔴 → last node of the list (next = null)

3️⃣ Analogy to Understand

Think of a train 🚂:

Each coach = a node

Passengers inside coach = data

Coupling between coaches = next pointer

First coach = head

Last coach = tail

4️⃣ Basic Operations
Operation	Description	Complexity
Insert at Front ⬆️	Add a node before head	O(1)
Insert at Back ⬇️	Add a node after tail	O(n)
Delete Front 🧹	Remove first node (head)	O(1)
Delete Back 🧹	Remove last node	O(n)
Search 🔍	Find node by value	O(n)
Traverse / Display 👀	Visit all nodes in order	O(n)
Count Nodes 🔢	Total number of nodes	O(n)


5️⃣ Visual Representation
Head 🟢 -> [10 | ➡️] -> [20 | ➡️] -> [30 | ➡️] -> null


Head points to first node (10)

Each node points to the next node (next pointer)

Last node (30) points to null → indicates end of list

6️⃣ Advantages ✅

Dynamic size (can grow/shrink)

Fast insertion/deletion at front

Memory efficient for frequent updates

7️⃣ Disadvantages ❌

Accessing nth node takes O(n) → no direct access like arrays

Uses extra memory for next pointer

Can traverse only in one direction

8️⃣ Memory Structure

Each node stores:

+-------+-------+
| Data  | Next  |
+-------+-------+


Next stores address of next node

Last node’s next = null
