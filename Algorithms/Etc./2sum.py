"""
2 Sum Problem: Two - Pointer Technique
Solution #1) O(n^2) - Search for all possible pairs
Solution #2) O(n log n) - Search for (sum-num) using binary 
             search which is O(log n).
Solution #3) O(n) - Search for (sum-num) but store all values
                    in hash map to speed up search - O(1).
"""

# Solution #1
def sol_1(arr, sum):
    sols = []
    for i in arr: # O(n)
        for j in arr: # O(n)
            if j != i:
                if i + j == sum:
                    sols.append((i,j))
                    
    return sols

# Solution #2 
def sol_2(arr, sum):
    sols = []
    for i in arr: # O(n)
        if sum-i in arr: # O(log n)
            sols.append((i, sum-i))
    
    return sols

# Solution 3 
def sol_3(arr, sum):
    hash = {}
    sols = []
    # Build - Excluded from Time Complexity
    for n in arr:
        hash[n] = 0
    
    for i in arr: # O(n)
        if sum-i in hash.keys(): # O(1)
            sols.append((i, sum-i))
    
    return sols

print sol_1([1, 4, 5, 6, 7, 9, 9, 10], 11)
print sol_2([1, 4, 5, 6, 7, 9, 9, 10], 11)
print sol_3([1, 4, 5, 6, 7, 9, 9, 10], 11)