# SNHU Data Structures and Algorithms for Linked Lists

## What is a Linked List?

A data structure that contains a head, tail and length property

Linked Lists consist of nodes, and each node has a value and pointer to either another node or null

## How is it different from an array?

#### **Lists**

- Do NOT have indexes
  - Makes it harder than array to access a specific item, need to go through entire list until specific item is found
- Connected via nodes with a **next** pointer
- Random access is not allowed
  - Cannot directly access 10th item, for example, must go through whole list
- Good when you need constant time for insertion and deletion

#### **Arrays**

- Indexed in order
- Insertion and Deletion can be expensive
- Can quickly be accessed at a specific index
