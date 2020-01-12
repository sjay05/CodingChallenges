"""
Binary Indexed Tree / Fenwick Tree:
update = O(log n)
query = O(log n)

Link = https://cses.fi/book/book.pdf
"""

import sys

arr = [0, 1, 3, 4, 8, 6, 1, 4, 2]
tree = [0] * len(arr)
n = len(arr)-1

def add(k, x):
    while k <= n:
        tree[k] += x
        k += k&-k
    
def sum_f(k):
    s = 0
    while (k > 0):
        s += tree[k]
        k -= k&-k
    
    return s

def sum_q(a, b):
    return sum_f(b) - sum_f(a-1)

def cnstrctBIT():
    for index in range(1, len(arr)):
        add(index, arr[index])

if __name__ == "__main__":
    cnstrctBIT()
    print sum_q(3, 7)