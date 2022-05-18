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

## Methods for Singly Linked Lists

- append: add a new node to end of list
- prepend: add a new node to beginning of list
- remove: remove an existing node from list
- insert: insert a new node anywhere in list
- search: Find an existing node in list
- reverse: reverse order of nodes in list

### Pseudocode for Singly Linked List Methods

```
FUNCTION append (value):

  newNode = value
  IF head == NULL:
    head = newNode
    tail = newNode
  ELSE
    tail->next = newNode
    tail = newNode
  ENDIF

END
```

```
FUNCTION prepend (value):

  newNode = value
  IF head == NULL:
    head = newNode
    tail = newNode
  ELSE
    newNode->next = head
    head = newNode
  ENDIF

END
```

```
FUNCTION remove (id):

  temp = head;
  IF head.id == id:
    head = NULL
  ELSE
    WHILE temp.id != id:
      prevNode = temp
      temp = temp->next
    ENDWHILE

    prevNode->next = temp->next
  ENDIF

END
```

```
FUNCTION search (id):

  current = head
  WHILE current != NULL:
    IF current.id != id:
      current = current->next
    ELSE
      RETURN current
    ENDIF
  ENDWHILE

END
```
