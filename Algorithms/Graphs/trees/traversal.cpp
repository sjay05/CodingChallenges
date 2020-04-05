/*===================================
#	Author:		sjay05
#	File:		traversal.cpp
#	Desc:		Tree Traversal
===================================*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 0x3f3f;
vector<vector<int>> adj(MAXN);

/*
@param s current node s
@param e previous node e
*/
void dfs(int s, int e) {
    cout << s << endl;
    for (auto u : adj[s]) {
        if (u != e) dfs(u, s);
    }
}

int main() {
    adj[2].push_back(5);
    adj[2].push_back(6);
    adj[6].push_back(8);
    dfs(2, -1);
}