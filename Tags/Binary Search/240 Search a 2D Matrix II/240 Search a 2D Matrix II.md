# 240. Search a 2D Matrix II

Careful: Yes
Index: 240
Programming Language: C++
Tags: Binary Search
Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row, col = 0, len(matrix[0])-1
        while row < len(matrix) and col >= 0:
            top_right = matrix[row][col]
            if top_right == target: return True
            if top_right > target: col -= 1
            else: row += 1
        return False
```