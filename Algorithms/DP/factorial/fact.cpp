#include <bits/stdc++.h>

using namespace std;

/*
Recursive (Top-Down) Approach:
    fact(10) = 10 * fact(9)
    = 9 * fact(8)
    = 8 * fact(7)
    = 7 * fact(6)
    ...
*/
int fact(int x) {
    if (x == 1) return 1;
    else return x * fact(x-1);
}

/*
DP (Bottom-up/Tabulation) Approach:
*/
int fact_tabulate(int x) {
    int dp[x];
    for (int i = 0; i < x; i++) {
        if (i == 0) {
            dp[i] = 1;
        } else {
            dp[i] = (i+1) * dp[i-1];
        }
    }
    return dp[x-1];
}

int main() {
    cout << fact_tabulate(5) << endl;
}