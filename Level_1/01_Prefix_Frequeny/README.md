# Overview
This repository provides an introduction to the concepts of Prefix Sum and Partial Sum, and includes example C++ code demonstrating how to implement and use these techniques.

## Prefix Sum

### What is a Prefix Sum?
A prefix sum is an array where each element at index `i` is the sum of the elements from the start of the array up to index `i`. It’s a useful concept for answering range sum queries efficiently.

### Why Use Prefix Sums?
Prefix sums are particularly useful for answering range sum queries quickly. Instead of recalculating the sum of a subarray every time, you can use the prefix sum array to find the sum in constant time.

### Example
Given an array `arr = [1, 2, 5, 10, 12, 6, 7]`, the prefix sum array is `[1, 3, 8, 18, 30, 36, 43]`.

To calculate the sum of elements between indices `a` and `b` in constant time, we can use:
\[ \text{sum}(a, b) = \text{prefix}[b] - \text{prefix}[a-1] \]

If \( a = 0 \):
\[ \text{sum}(0, b) = \text{prefix}[b] \]

## Partial Sum

### What is a Partial Sum?
A partial sum is a technique used to perform range updates efficiently. Instead of updating each element in a range directly, we mark the beginning and the end of the range with the update value and then compute the final values using a cumulative sum.

### Example
Given an array `arr = [0, 0, 0, 0, 0]` and a range update `(a, b, k)` which means adding `k` to each element from index `a` to `b`:

1. Increment `arr[a]` by `k`.
2. Decrement `arr[b+1]` by `k`.

After applying all updates, compute the cumulative sum to get the final updated array.
