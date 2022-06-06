# SNHU Data Structures and Algorithms for Trees

## What is a Tree?

A **tree** is a data structure that stores elements in a hierarchy.

- These elements are referred to as **nodes** and the lines that connect them are known as **edges**.
- The top node in the tree is called the **root**.
- A node directly connected to another node when moving away from the root is referred to as a **child**
- A node that has a child is referred to as its **parent**
- nodes with the same parent are referred to as **siblings**
- Nodes that don't have children are referred to as a **leaf**

## Binary Search Trees

A Tree with nodes that are allowed a maximum of two children are known as a **Binary Tree**

A **Binary Search Tree** (BST) is a special type of binary tree that allows us to quickly look up data.

In a BST, the value of any node is always greater than the value of its left child and less than the value of it right child.

Search, Insert and Delete methods in BST may be as small as `O(log n)` runtime, yielding extremely fast searches.

## Pseudocode

Insert

```
FUNCTION Insert (root, value):

IF root is NULL:
  RETURN new Node with value as arg
ENDIF

IF value > root->value:
  root->right = Insert(root->right, value)
ELSE:
  root->left = Insert(root->left, value)
ENDIF

END
```

Remove

```
FUNCTION Remove (root, key):

IF root is NULL:
  RETURN root
ENDIF

IF key < root->key:
  root->left = Remove(root->left, key)
ELSE IF key > root->key:
  root->right = Remove(root->right, key);
ELSE:
  IF root->left is NULL AND root->right is NULL:
    RETURN NULL
  ELSE IF root->left is NULL:
    root = root->right
  ELSE IF root->right is NULL:
    root = root->left
  ELSE
    GET the inorder successor (leftmost child of right subtree)
    DELETE inorder successor

ENDIF

END
```

Search

```
FUNCTION Search (root, key):

IF root is NULL OR root->key is key:
  RETURN root
ENDIF

IF root->key < key:
  RETURN Search(root->right, key)
ELSE:
  RETURN Search(root->left, key)
ENDIF

END
```
