#include <bits/stdc++.h>

using namespace std;

/*
Sources: CP-Algorithms

Finding Articulation Points in a Graph in O(N + M).

- An articulation point in a graph is a vertex when removed
with its associate edges makes the graph disconnected.

Algorithm:
- There are two cases in this algorithm:

1) Pick a DFS from node (v) which is not root. If none
of the descendants of this node (v) have a path to a ancestor,
it is clearly an articulation point.

2) DFS from root; It will only be a articulation point if
vertex has more than one child in the DFS tree.
*/

int n = 100;
vector<vector<int>> adj(n);

vector<int> visited(n, false);
vector<int> tin(n, -1), low(n, -1);
int timer = 0;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : adj[v]) {
        if (to == p)
            continue;
        if (visited[to])
            low[v] = min(low[v], tin[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1) {
                printf("Articulation Point: %i\n",v);
            }
            ++children;
        }
    }
    if (p == -1 && children > 1) {
        printf("Articulation Point: %i\n",v);
    }
}

void mk(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

/*
Graph To be Tested:

1 \
|  0 - 3
2 /   |
      4
*/

int main() {
    mk(1, 2); mk(2, 0);
    mk(1, 0); mk(0, 3);
    mk(3, 4);

    dfs(0, -1);
}
