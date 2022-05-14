# SNHU Data Structures and Algorithms for Recursion

## What is recursion?

A process (function) that calls itself

Invoke the same function with a different input until you reach the **base case**

Example:

```
FUNCTION sumRange (num):
  IF num == 1:
    RETURN 1
  ELSE
    RETURN num + sumRange(num - 1)
  ENDIF
```

Each function call is added to the call stack as it waits for the result of the next function called, in this case itself

It will keep doing this until it reaches the base case, in this case 1

```
sumRange(3)
    return 3 + sumRange(2)
                    return 2 + sumRange(1)
                                  return 1

  6
    return 3 + 3
                return 2 + 1
                            return 1
```
