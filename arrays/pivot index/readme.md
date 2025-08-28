# Problem: Pivot Index

The **pivot index** is the index in an array where the sum of all elements to its left is equal to the sum of all elements to its right. Your task is to find the leftmost such index. If no such index exists, return -1.

For example, in the array `[1, 7, 3, 6, 5, 6]`, the pivot index is **3**.

* The sum of elements to the left of index 3 (`1 + 7 + 3`) is 11.
* The sum of elements to the right of index 3 (`5 + 6`) is 11.

---

### Solution 1: Brute-Force Approach

This is the most straightforward method. We simply check every single index to see if it qualifies as a pivot index.

#### Logic

We'll use a loop to iterate through each index of the array. For each index, we'll calculate the sum of all elements to its left and the sum of all elements to its right. If these two sums match, we've found our answer, so we return the current index. If we finish the loop without finding a match, no pivot index exists, and we return -1.

#### Complexity Analysis

* **Time Complexity:** $O(n^2)$. We use a nested loop structure. The outer loop runs through each element, and the inner loops for calculating the left and right sums also run up to $n$ times.
* **Space Complexity:** $O(1)$. We don't use any extra space that scales with the size of the input array.

---

### Solution 2: Optimal Approach (Prefix Sum)

We can significantly improve performance by optimizing our calculations. Instead of repeatedly summing subarrays, we can use a single pass to find the pivot index.

#### Logic

1.  First, calculate the **total sum** of all elements in the array.
2.  Then, iterate through the array from left to right, maintaining a running `leftSum`, which starts at zero.
3.  For each element at index `i`, we can compute the `rightSum` using this simple formula: `rightSum = totalSum - leftSum - nums[i]`.
4.  If `leftSum` equals `rightSum`, we've found our pivot index and can return `i`.
5.  After each check, we update `leftSum` by adding the current element `nums[i]` to it for the next iteration.

This method avoids redundant computations by leveraging the pre-calculated total sum.

#### Complexity Analysis

* **Time Complexity:** $O(n)$. We make two passes through the array—one to get the total sum and one to find the pivot index. This makes the overall time complexity linear.
* **Space Complexity:** $O(1)$. We only need a few variables to store the sums, so space usage is constant.

---
