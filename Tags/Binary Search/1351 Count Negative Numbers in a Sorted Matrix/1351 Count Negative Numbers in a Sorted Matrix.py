class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        # 4, 3, 2,  -> -1 <-
        # 3, 2, 1, -1
        # 1, 1, -1, -2
        # -1, -1, -2, -3
        row, col = 0, len(grid[0])-1
        count = 0
        while row < len(grid) and col >= 0:
            top_right = grid[row][col]
            if top_right >= 0: row += 1
            else: 
                count += len(grid)-row
                col -= 1
        return count
