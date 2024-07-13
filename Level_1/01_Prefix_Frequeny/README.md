
# Prefix Sum and Partial Sum in C++

## Overview
This repository introduces the concepts of Prefix Sum and Partial Sum, demonstrating their implementation in C++ and their practical applications.

## Prefix Sum

### What is a Prefix Sum?
A prefix sum is an array where each element at index `i` is the sum of the elements from the start of the array up to index `i`. It’s a useful concept for answering range sum queries efficiently.

### Why Use Prefix Sums?
Prefix sums are particularly useful for answering range sum queries quickly. Instead of recalculating the sum of a subarray every time, you can use the prefix sum array to find the sum in constant time.

### Example:
Given an array `arr = [1, 2, 5, 10, 12, 6, 7]`, its prefix sum array is `[1, 3, 8, 18, 30, 36, 43]`.

To compute the sum of elements between indices `a` and `b` in constant time:
```
sum(a, b) = prefix[b] - prefix[a - 1]
```

If `a = 0`:
```
sum(0, b) = prefix[b]
```

## Partial Sum

### What is a Partial Sum?
Partial Sum facilitates efficient range updates by marking the start and end of a range with an update value, then computing the final values using cumulative sums instead of updating each element individually.

### Example:
Given an array `arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]` and two range updates:

1. Update `(2, 7, 1)`:
    - Increment `arr[2]` by `1`.
    - Decrement `arr[8]` by `1`.

2. Update `(4, 9, 3)`:
    - Increment `arr[4]` by `3`.
    - Decrement `arr[10]` by `3`.

After applying all updates, compute the cumulative sum to obtain the final updated array: `[0, 1, 1, 4, 4, 4, 4, 3, 3, 0]`.

## Implementation in C++
This repository includes implementations of these concepts in C++, showcasing how to build and utilize prefix and partial sums effectively. Check the source code files for detailed examples and usage.

## Practical Applications
- **Range Sum Queries**: Quickly find the sum of elements in a subarray.
- **Range Updates**: Efficiently apply updates to subarrays without recalculating from scratch.

Explore the code and examples provided to understand and leverage the power of prefix and partial sums in your own projects.
