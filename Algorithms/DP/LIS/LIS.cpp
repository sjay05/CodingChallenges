/*
Longest Increasing Subsequence: DP
Time Complexity: O(N^2)
...can be changed to O(n log n) with further improvements in search...
*/

#include <bits/stdc++.h>

using namespace std;

// Index      0  1  2  3  4  5  6  7
int arr[8] = {6, 2, 5, 1, 7, 4, 8, 3};
#define MAXN sizeof(arr)/sizeof(arr[0])

int calc_lis_dp() {
    int dp[MAXN]; int n = MAXN;
    for (int k = 0; k < n; k++) {
        dp[k] = 1;
        for (int i = 0; i < k; i++) {
            if (arr[i] < arr[k]) {
                dp[k] = max(dp[k], dp[i]+1);
            }
        }
    }
    int msf = 0;
    for (int x: dp) {
        if (x > msf) msf = x;
    }
    return msf;

}

int main() {
    cout << calc_lis_dp() << endl;
}