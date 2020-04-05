/*===========================================
#	Author:		sjay05
#	File:		dp.cpp
#	Desc:		Dynamic Programming on Trees
============================================*/
#include <bits/stdc++.h>

using namespace std;

/*
DP can be used to calculate information 
during a tree traversal. We are going to
find the number of nodes in a subtree as 
an example. dp[s] = number of nodes in 
subtree including (s) itself.
*/

const int MAXN = 100;
vector<vector<int>> adj(MAXN);

int dp[MAXN];
void dfs(int s, int e) {
    dp[s] = 1;
    for (auto u : adj[s]) {
        if (u == e) continue;
        dfs(u, s);
        dp[s] += dp[u];
    }
}

int main() {
    adj[2].push_back(5);
    adj[2].push_back(6);
    adj[6].push_back(8);
    dfs(2, -1);
    cout << dp[2] << endl;
}