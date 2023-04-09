# 366. Find Leaves of Binary Tree

Careful: No
Index: 366
Programming Language: C++
Tags: Binary Tree
Link: https://leetcode.com/problems/find-leaves-of-binary-tree/

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        def recurse(node):
            if not node:
                return None
            if not(node.left or node.right):
                res[-1].append(node.val)
                return None
            node.left = recurse(node.left)
            node.right = recurse(node.right)
            return node
        while root:
            res.append([])
            root = recurse(root)
        return res

```