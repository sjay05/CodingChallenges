import sys

coins = [1, 2, 3, 4]
coins = coins[::-1] # reverse array
target = 7

# Memoization Variables
maxn = 9999
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

"""
Use memoization to efficiently calculate
values of a recursive function.
- Store in int value[] and bool ready[]
"""
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

"""
Basically work your way from solve(0) to solve(x)
Ex. coins = [1, 3, 4]; Target = 7
Make DP array with length of target stored with inf
except 0.
[0, inf, inf, inf, inf, inf, inf]
Find MINIMUM number of coins from (c being coin) --> dp[x] = min(dp[x], dp[x-c]+1) 
The array should become:
[0, 1, 1, 1, 1, 2, 2, 2]
Last INDEX is your answer.
We also can store the coin being choosed, and backtrack
to see which coins create a smallest set.
"""
def solve_TOPDOWN(x):
    dp = [x+1] * (x+1)
    dp[0] = 0
    for i in range(1, len(dp)):
        for c in coins:
            if (i - c >= 0):
                dp[i] = min(dp[i], dp[i-c]+1)
    
    dp[-1]

if __name__ == "__main__":
    #print solve_NON_DP(target)
    #print solve_WITH_DP(target)
    print solve_TOPDOWN(target)