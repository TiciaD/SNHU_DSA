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
