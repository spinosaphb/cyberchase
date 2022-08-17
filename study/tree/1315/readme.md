## 1315. Sum of Nodes with Even-Valued Grandparent 
<span style='color: orange'>Medium</span>

---

Given the `root` of a binary tree, return the sum of values of nodes with an **even-valued** **grandparent**. If there are no nodes with an **even-valued** **grandparent**, return `0`.

A **grandparent** of a node is the parent of its parent if it exists.


### **Example 1:**

![IMAGE 0](https://assets.leetcode.com/uploads/2021/08/10/even1-tree.jpg)

**Input:** 
```cpp
root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
```

**Output:**
```cpp
18
```

**Explanation:** The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.

### **Example 2:**

![IMAGE 1](https://assets.leetcode.com/uploads/2021/08/10/even2-tree.jpg)

**Input:** 
```cpp
root = [1]
```

**Output:**
```cpp
0
```

### Constraints:

The number of nodes in the tree is in the range `[1, 104]`.
`1 <= Node.val <= 100`


### Details:
<span style='color:green'>Success</span>

*Runtime:* 48 ms, faster than 94.68% of C++ online submissions for Sum of Nodes with Even-Valued Grandparent.

*Memory Usage:* 41.5 MB, less than 43.56% of C++ online submissions for Sum of Nodes with Even-Valued Grandparent.
