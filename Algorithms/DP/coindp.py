import sys

coins = [1, 2, 3, 4, 5, 6, 7]
coins = coins[::-1] # reverse array
target = 213

# Memoization Variables
maxn = 100000
ready = [False] * maxn
value = [0] * maxn

"""
Recursive Greedy Approach: 
Pick greatest number.
Ex. coins = {1,2,3}, target = x

    solve(x) = min(solve(x-1)+1,

                   solve(x-2)+1,
                   
                   solve(x-3)+1)
"""

def solve_NON_DP(x):
    if x == 0:
        return 0
    for i in coins:
        if x - i >= 0:
            return solve_NON_DP(x-i)+1

def solve_WITH_DP(x):
    if x == 0:
        return 0
    if ready[x]:
        return value[x]
    for i in coins:
        if x - i >= 0:
            val = solve_WITH_DP(x-i)+1
            ready[x] = True
            value[x] = val
            return val

if __name__ == "__main__":
    print solve_NON_DP(target)