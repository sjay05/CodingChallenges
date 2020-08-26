/* --- 0-1 Knapsack Problem --- */
#include <bits/stdc++.h>

using namespace std;

/*
Problem Structure:
 Given [n] types of statements, where the i'th item
 type has integer size s_i and a value v_i, we need
 to fill a knapsack of total capacity of C with items
 of maximum value. We can only add an item 0 or 1 times.

Dynamic Programming Structure:
 j = size
 i = items(1..i)

 M(i,j) = max(m[i-1, j], m[i-1, j-si]+vi)

 if wi > w (the new item is greater the weight limit), we exclude
 and call M(i-1, j)

 M(i-1, j) : We are not selecting the i'th item and j remains the
             same, because we are not adding or taking away from
             the knapsack.

 M(i-1, j-si) + vi : We have selected the i'th item. This reduces
                     knapsack size to (i - si) and we add vi to the
                     optimal solution. There are (i-1) items left.


Input Specifications:
 - stdin is collected from
 https://en.wikipedia.org/wiki/Knapsack_problem
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

int knapsack(int c, int n) {
    /*
     * @param n = # of items
     * @param c = total size
     */
    int dp[n + 1][c + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            auto it = items[i - 1];
            if (it.size > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - it.size] + it.value);
            }
        }
    }
    return dp[n][c];

}

int main() {
    printf("%i\n", knapsack(C, items.size()));
}