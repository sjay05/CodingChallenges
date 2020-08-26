/* --- LONGEST INCREASING SUBSEQUENCE --- */
#include <bits/stdc++.h>

using namespace std;

/*
Problem Statement:
 Given a sequence of [n] numbers [A1...An], find
 a subsequence of maximum length in which the
 values form a increasing sequence.

 Ex. (5,6,2,3,4,1,9,9,8,9,5) => LIS => (2,3,4,8,9)

Dynamic Programming Structure:
 Let L(i) be the subseq starting at A[0] and ending
 at A[i]. We build a recurrence to select some earlier
 position [j] that can be extended to get a max subseq.

 As every number can be its own subseq, we assign all indexes
 of dp as 1.
*/

int lis(vector<int> &arr, int n) {
    /*
     * @param n = arr.size()
     */
    vector<int> dp(n);
    dp.assign(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int ma = 0;
    for (int i = 0; i < dp.size(); i++) {
        ma = max(ma, dp[i]);
    }
    return ma;
}

int main() {
    //vector<int> a = {5,6,2,3,4,1,9,9,8,9,5};
    vector<int> a = {3,1,6,5,2,4};
    printf("%i\n", lis(a, a.size()));
}