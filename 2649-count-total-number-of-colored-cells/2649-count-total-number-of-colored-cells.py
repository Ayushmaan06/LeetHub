class Solution:
    def coloredCells(self, n: int) -> int:
        x = n - 1
        x = x * (4 + 4 * x) // 2
        return x + 1
