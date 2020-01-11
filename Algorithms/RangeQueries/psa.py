"""
Prefix Sum Array:
- Construction Time: O(n)
- Range Query Time: O(1)
- Brute Force Method: O(nq)

Ex.
       0  1  2  3  4  5  6  7
arr = [1, 3, 4, 8, 6, 1, 4, 2]

       0  1  2  3   4   5   6   7
psa = [1, 4, 8, 16, 22, 23, 27, 29]

Range Query = query[i, j]  = psa[j] - psa[i-1]
"""

import sys

def build_psa(arr):
    psa = []
    sum = 0
    for i in arr:
        sum += i
        psa.append(sum)
    
    return psa

def range_query(i, j, arr):
    psa = build_psa(arr)
    if i == 0:
        return psa[j]
    else:
        return psa[j] - psa[i-1]


print range_query(3, 6, [1, 3, 4, 8, 6, 1, 4, 2])
