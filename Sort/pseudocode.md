# SNHU Data Structures and Algorithms for Sort

## What is Sorting?

Sorting is the process of rearranging the items in a collection (i.e. an array) so that the items are in some kind of order

Examples:

- Sorting numbers from smallest to largest
- Sorting names alphabetically
- Sorting movies based on release year

### Helper Swap function

Most sorting algorithms involve some type of swapping functionality so it's good to abstract that logic to make the code cleaner and reusable

```
FUNCTION Swap (array, index1, index2):

  VAR temp = array[index1]
  array[index1] = array[index2]
  array[index2] = temp

END
```

## Common Sort Algorithms

Common Basic Sorting Algorithms include:

- Bubble Sort
- Selection Sort
- Insertion Sort

### Bubble Sort

A sorting algorithm where the largest value **_bubbles_** to the top.

Loop through and compare each item to the next, if the next is smaller then swap their places

```
FUNCTION BubbleSort (array):

  FOR (i = end of array to beginning of array):
    FOR (j = beginning of array to i - 1) :
      IF array[j] is greater than array[j + 1]:
        CALL Swap (array, array[j], array[j + 1])
      ENDIF
    ENDFOR
  ENDFOR

  RETURN array

END
```

### Selection Sort

```
// loop over unsorted array starting at element at first position and ending at second to last element
FOR (i = 0; i < numbersSize - 1; ++i) {

   // Find index of smallest remaining element
   smallest = i
   // loop over unsorted array starting at current element + 1 and ending at last element
   for (j = i + 1; j < numbersSize; ++j) {
      // if current element + 1 is less than smallest remaining element
      if (numbers[j] < numbers[smallest]) {
        // current element + 1 becomes smallest remaining element
        smallest = j
      }
   }

   // Swap current element and smallest remaining element
   temp = numbers[i]
   numbers[i] = numbers[smallest]
   numbers[smallest] = temp
```

Common Fast Sorting Algorithms include:

- Quick Sort
- Merge Sort
- Radix Sort

### Quick Sort

```
/* Partition function takes last element as pivot, places the pivot element at its   correct position in sorted array, and places all smaller elements to left of pivot and all greater elements to right of pivot */

FUNCTION Partition(numbers, lowIndex, highIndex):
  // Pick middle element as pivot
  midpoint = lowIndex + (highIndex - lowIndex) / 2

  done = false
  while (!done) {
    // Increment lowIndex while numbers[lowIndex] < numbers[midpoint]
    while (numbers[lowIndex] < numbers[midpoint]) {
        lowIndex += 1
    }

    // Decrement highIndex while numbers[midpoint] < numbers[highIndex]
    while (numbers[midpoint] < numbers[highIndex]) {
        highIndex -= 1
    }

    // If zero or one elements remain, then all numbers are partitioned and loop can end
    if (lowIndex >= highIndex) {
      // stop loop
      done = true
    }
    else {
      // Swap numbers[lowIndex] and numbers[highIndex]
      temp = numbers[lowIndex]
      numbers[lowIndex] = numbers[highIndex]
      numbers[highIndex] = temp

      // Update lowIndex and highIndex
      lowIndex += 1
      highIndex -= 1
    }
  }

  RETURN highIndex


FUNCTION Quicksort(numbers, lowIndex, highIndex):
   // Base case: If the partition size is 1 or zero elements, then partition is already sorted
   if (lowIndex >= highIndex) {
      // Stop the recursion
      return
   }

   // Partition the data within the array
   // index of the low partition's last element is returned
   lowEndIndex = Partition(numbers, lowIndex, highIndex)

   // Recursively sort low partition (lowIndex to lowEndIndex)
   Quicksort(numbers, lowIndex, lowEndIndex)
   // and high partition (lowEndIndex + 1 to highIndex)
   Quicksort(numbers, lowEndIndex + 1, highIndex)

```
