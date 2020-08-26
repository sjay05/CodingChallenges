/* --- Integer Knapsack Problem [duplicate items] ---- */
#include <bits/stdc++.h>

using namespace std;

/*
Problem Statement:
 Given [n] types of items, where the i'th item
 type has integer size s_i and a value v_i, we need
 to fill a knapsack of total capacity of C with items
 of maximum value. We can add multiple items of the
 same type to the knapsack.

Dynamic Programming Structure:
 v = value, w = weight
 i is in [1..N]
 dp[0] = 0 (sum of zero items is 0)
 dp[i] = max(v1 + m[i - w1], v2 + m[i - w2] ,..., vi + m[i - wi])

 NOTE:
 For the statement above, we only include an item if its, weight
 is less than the current [i] to satisfy the problem statement.

Input Specifications:
 - stdin for test is collected from
 https://en.wikipedia.org/wiki/Knapsack_problem.
*/

struct item {
    int size;
    int value;
};

const int C = 15;
vector<item> items = {{2,  2},
                      {1,  1},
                      {4,  10},
                      {1,  2},
                      {12, 4}};

int knapsack(int c) {
    int dp[c + 1];
    dp[0] = 0;
    for (int i = 1; i <= c; i++) {
        int ma = 0;
        for (auto u : items) {
            if (u.size <= i) {
                ma = max(ma, u.value + dp[i - u.size]);
            }
        }
        dp[i] = ma;
    }
    return dp[c];
}

int main() {
    printf("%i\n", knapsack(C));
}