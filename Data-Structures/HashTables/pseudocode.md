# SNHU Data Structures and Algorithms for Hash Tables

## What is a Hash Table?

A data structure that stores unordered items by mapping (or hashing) each item to a location in an array (or vector)

Each has table array element is called a bucket and a hash function computes a bucket index from the item's key

## Hash Functions

A common hash function uses the **modulo operator %** which computes the remainder as an integer when dividing two numbers

For example:
A modulo hash function for a 50 entry hash table is key % 50

- key % 50 yields values from 0 to 49 (50 values counting 0)

## Collisions

A collision occurs when an item being inserted into a hash table maps to the same bucket as an existing item in the hash table

### Addressing Collisions

Chaining uses a list for each bucket where each list may store multiple items that map to the same bucket

- i.e. bucket 5 contains a list with [55, 75]

Open addressing is where collisions are resolved by looking for an empty bucket elsewhere in the table

---

## Chaining

Chaining uses a linked list to store multiple items at the same array index

Example: We have a hash table with a size of 5, giving you 5 buckets to store items these buckets start off null or empty

```
  0| |
  1| |
  2| |
  3| |
  4| |
```

Now we want to store a key value pair in the hash table
We won't store the value directly in the bucket, instead we wrap it in a Linked List node and have the bucket point to this node

```
Key = 6
Value = A

  0| |
  1| | -> [A]
  2| |
  3| |
  4| |
```

If we get another key value pair that gets assigned the same index, we go to the bucket at index 1 and store the value at the end of the linked list

```
Key = 11
Value = C

  0| |
  1| | -> [A] -> [C]
  2| |
  3| |
  4| |
```

## Open Addressing and Probing Algorithms

### **Linear Probing**

An algorithm that handles a collision by starting at the key's mapped bucket, and then linearly searches subsequent buckets until an empty bucket is found.

Instead of storing values in linked lists you store them directly in buckets.

The address of a key value pair is not determined by the hash function, we have to search for another empty bucket.

Example: Using the same hash table as before, we want to store a key value pair in the hash table and we will store at the index the hash function assigned

```
Key = 6
Value = A

  0|    |
  1|6, A|
  2|    |
  3|    |
  4|    |
```

If we get another key value pair that gets assigned the same index, we have to look for another empty bucket, we call this process _probing_. With **linear probing**, we start from the current bucket, if it's full, we go to next bucket, if that's full, we keep going forward until we find an empty slot.

If we can't find any empty slots, that means the table is full, a drawback to this approach that is not an issue with the chaining approach.

```
Key = 11
Value = C

  0|     |
  1|6, A | <-- Start Here - FULL
  2|11, C| <-- Next - AVAILABLE
  3|     |
  4|     |
```

Another issue with linear probing, is as you start filling the table, items start to form a cluster which causes issues when you get keys that fall in the same range.

```
  0|     |
  1|6, A | )
  2|11, C| ) CLUSTER
  3|8, B | )
  4|     |
```

Probing will take longer since you have to pass all items in the cluster to add the new item at the end, making the cluster bigger in the process.

```
Key = 21
Value = D

  0|     |
  1|6, A | <-- Start Here - FULL
  2|11, C| <-- Next - FULL
  3|8, B | <-- Next - FULL
  4|21, D| <-- Next - AVAILABLE
```

### **Quadratic Probing**

An algorithm that handles a collision by starting at the key's mapped bucket, then quadratically searches subsequent buckets until an empty bucket is found.

Quadratic probing helps solves linear probing's clustering problem since the key value pairs get spread out more widely.

Linear Probing algo = hash(key) + i  
Example: 1 2 3 4 5

Quadratic Probing algo = hash(key) + i<sup>2</sup>  
Example: 1 4 9 16 25

However this could potentially add another drawback because of the big jumps taken to find another bucket, there's a chance the algorithm will get back to the beginning of the array after it's first loop and make the same steps, essentially resulting in an infinite loop. This would not happen with linear probing.

### **Double Hashing**

An algorithm that handles a collision by using 2 different hash functions to compute bucket indices.

Instead of using `i` or `i^2` we'll use a separate independent hash function to calculate the number of steps, `i * hash2`.

### <u>Probing Algorithm comparison</u>

| Name        | Algorithm                          |
| ----------- | ---------------------------------- |
| Linear      | `(hash1 + i) % table_size`         |
| Quadratic   | `(hash1 + i^2) % table_size`       |
| Double Hash | `(hash1 + i * hash2) % table_size` |

---

## Common Hash Functions and Pseudocode

A hash table is fast if the hash function minimizes collisions.

A perfect hash function maps items to buckets with no collision, this can be created if the number of items and all possible item keys are known beforehand.

A good hash function should uniformly distribute items into buckets.

- With **chaining**, a good hash function results in short linked lists in each bucket allowing for fast inserts, searches and removes
- With **linear probing**, a good hash function will avoid hashing multiple items to consecutive buckets, lessening clusters and allowing for fast inserts, searches and removes

### Modulo Hash

**modulo hash** uses the remainder from dividing the key by hash table size
`moduloHash(int key) { return key % table_size }`

### Mid-square Hash

**mid-square hash** a seed value is taken and squared, then some digits from that result are extracted and they become the new seed.

The process of squaring and extracting middle digits reduces the likelihood of keys mapping to just a few buckets.

Example:

```
Key = 40, numOfBuckets = 100, digitsToExtract = 2

40 * 40 = 1600   // Middle 2 digits = 60
bucketIndex = 60 % 100 = 60
```

### Multiplicative String Hash

**multiplicative string hash** repeatedly multiplies the hash value and adds the ASCII (or Unicode) value of each character in the string.

## Pseudocode

Insert

```
FUNCTION Insert(int key):

  VAR index
  index = hashFunction(key);


  WHILE table[index] != NULL && table[index]->key != key:
    index = hashFunction(index + 1);
  ENDWHILE

  IF table[index] != NULL:
    DELETE table[index]
  ELSE:
    table[index] = new Node(key, value)
  ENDIF

END
```

Remove

```
FUNCTION Remove(key):

  VAR index
  index = hashFunction(key);


  WHILE table[index] != NULL:

    IF table[index]->key == key:
      break
    ELSE:
      index = hashFunction(index + 1)
    ENDIF

  ENDWHILE

  IF table[index] == NULL:
    RETURN "No Element found"
  ELSE:
    DELETE table[index];
  ENDIF

END
```

Search

```
FUNCTION Search(key):

  VAR index
  index = hashFunction(key);

  WHILE table[index] != NULL && table[index]->key != key:
    index = hashFunction(index + 1);
  ENDWHILE

  IF table[index] == NULL:
    RETURN -1
  ELSE:
    RETURN table[index]->value;
  ENDIF

END
```
