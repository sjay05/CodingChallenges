#include <bits/stdc++.h>

using namespace std;

vector<int> coins = {1, 2, 3, 4, 5, 6, 7};
int target = 21;

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

int main() {
    reverse(coins.begin(), coins.end());
    //cout << solve_NON_DP(target) << endl;
    cout << solve_WITH_DP(target) << endl;
}