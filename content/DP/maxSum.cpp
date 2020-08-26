/* --- MAXIMUM VALUE CONTIGUOUS SEQUENCE --- */
#include <bits/stdc++.h>

using namespace std;

/*
Problem Structure:
 Given an array of n numbers, provide an algorithm for finding a
 contiguous subsequence A(i)...A(j) for which the sum of elements
 is maximum. Example: {1, -3, 4, -2, -1, -6} - seq (4, -2, -1, 6) = 7.

Recursive Structure:
 To find the maximum sum we can do one of the following:
 1) either extend the old sum by adding A[i]
 2) start a new window starting with one element A[i]

Simulation:
             0   1  2   3   4  5
int arr[] = {1, -3, 4, -2, -1, 6}
          = {1,  0, 0,  0,  0, 0}
          = {1,  0, 0,  0,  0, 0}
          = {1,  0, 4,  0,  0, 0}
          = {1,  0, 4,  2,  0, 0}
          = {1,  0, 4,  2,  1, 0}
          = {1,  0, 4,  2,  1, 7}
 */

int maxSum(vector<int> &arr, int N)
{
    vector<int> dp(N);
    if (arr[0] > 0)
        dp[0] = arr[0];
    for (int i = 1; i < N; i++)
        if (dp[i - 1] + arr[i] > 0)
            dp[i] = dp[i - 1] + arr[i];

    int ret = 0;
    for (int i = 0; i < dp.size(); i++)
        ret = max(ret, dp[i]);
    return ret;
}

int main()
{
    vector<int> v = {1, -3, 4, -2, -1, 6};
    printf("%i\n", maxSum(v, v.size()));
}