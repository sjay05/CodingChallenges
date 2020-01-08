"""
Paths on a Grid:
- Find path from (src to dest) with greatest sum.
Algorithm:
- Recursive function calling on f(x+1, y) and f(x, y+1)
"""
import sys

grid = [
    [3, 7, 9, 2, 7],
    [9, 8, 3, 5, 5],
    [1, 7, 9, 8, 5],
    [3, 8, 6, 4, 10],
    [6, 3, 9, 7, 8]
]

src = (0, 0)
dest = (4, 4)

def check(x, y):
    if x <= len(grid[0])-1 and y <= len(grid)-1:
        return True
    return False


def find_path(x, y, count):
    if (x,y) == dest:
        return count + grid[x][y]
    if check(x, y):
        count += grid[x][y]
    if not check(x, y):
        return 
    else:
        return max(find_path(x+1, y, count), find_path(x, y+1, count))


if __name__ == "__main__":
    print find_path(0, 0, 0)
