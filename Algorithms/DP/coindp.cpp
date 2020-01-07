#include <bits/stdc++.h>

using namespace std;

vector<int> coins = {1, 2, 3, 4};
int target = 7;

// Memoization Variables
const int MAXN = 100;
int value[MAXN];
bool ready[MAXN];

/*
Recursive Greedy Approach: 
Pick greatest number.
Ex. coins = {1,2,3}, target = x

    solve(x) = min(solve(x-1)+1,

                   solve(x-2)+1,
                   
                   solve(x-3)+1)
*/
int solve_NON_DP(int x) {
    if (x == 0) return 0;
    for (int i : coins) {
        if (x - i >= 0) {
            return solve_NON_DP(x-i)+1;
        }
    }
    return 0;
}

/*
Use memoization to efficiently calculate
values of a recursive function.
- Store in int value[] and bool ready[]
*/
int solve_WITH_DP(int x) {
    if (x == 0) return 0;
    if (ready[x]) return value[x];
    for (int i : coins) {
        if (x - i > 0) {
            int val = solve_WITH_DP(x-i)+1;
            ready[x] = true;
            value[x] = val;
            return val;
        }
    }
    return 0;
}  

/*
Basically work your way from solve(0) to solve(x)
Ex. coins = [1, 3, 4]; Target = 7
Make DP array with length of target stored with inf
except 0.
[0, inf, inf, inf, inf, inf, inf]
Find MINIMUM number of coins from (c being coin) --> dp[x] = min(dp[x], dp[x-c]+1) 
The array should become:
[0, 1, 1, 1, 1, 2, 2, 2]
Last INDEX is your answer.
*/
int solve_TOPDOWN(int x) {
    int dp[x]; dp[0] = 0;
    for (int i = 1; i < x; i++) {
        dp[i] = x+1;
        for (int c : coins) {
            if (i-c >= 0) {
                dp[i] = min(dp[i], dp[i-c]+1);
            }
        }
    }
    return dp[x-1];
}

int main() {
    reverse(coins.begin(), coins.end());
    //cout << solve_NON_DP(target) << endl;
    //cout << solve_WITH_DP(target) << endl;
    cout << solve_TOPDOWN(target) << endl;
}