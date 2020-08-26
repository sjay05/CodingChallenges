#include <bits/stdc++.h>

using namespace std;

int fib(int n)
{
    int dp[n];
    if (n == 0 or n == 1)
        return 1;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}

int main()
{
    printf("%d\n", fib(6));
}
