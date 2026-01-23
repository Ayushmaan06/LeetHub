class Solution:
    def countCollisions(self, direction: str) -> int:
        n = len(direction)
        left = 0
        while left < n and direction[left] == 'L':
            left += 1
        right = n - 1
        while right >= 0 and direction[right] == 'R':
            right -= 1

        # nothing that can collide
        if left > right:
            return 0

        # count moving cars in the unsafe part
        collisions = 0
        for i in range(left, right + 1):
            if direction[i] != 'S':          # 'L' or 'R'
                collisions += 1
        return collisions