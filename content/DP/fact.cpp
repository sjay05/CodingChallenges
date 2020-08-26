#include <bits/stdc++.h>

using namespace std;

int fact(int n)
{
    int dp[n + 1];
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = i * dp[i - 1];
    }
    return dp[n];
}

int main()
{
    printf("%d\n", fact(5));
}