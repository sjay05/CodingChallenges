"""
Longest Increasing Subsequence: DP
Time Complexity: O(N^2)
...can be changed to O(n log n) with further improvements in search...
"""
import sys

#      0  1  2  3  4  5  6  7
arr = [6, 2, 5, 1, 7, 4, 8, 3]

MAXN = len(arr)

def calc_lis_dp():
    dp = [0] * MAXN
    n = MAXN
    for k in range(n):
        dp[k] = 1
        for i in range(k):
            if arr[i] < arr[k]:
                dp[k] = max(dp[k], dp[i]+1)

    msf = 0
    for x in dp:
        if x > msf: 
            msf = x
    
    return msf

if __name__ == "__main__":
    print calc_lis_dp()