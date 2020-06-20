#include <bits/stdc++.h>

using namespace std;

/*
Sources: CP-Algorithms

Offline Algorithm to Find Bridges:

- Given a directed graph (all connected CC), a bridge
is an edge that once removed it makes the graph no
longer connected. Find all such bridges in a graph.

Naive Algorithm:
- Try all edges and find the number of connected components.
- Time Complexity : O(M(N + M))

Relation to Real World:
- Given roads in a city, find which ones are important to maintain
cause if they are destroyed then people cannot reach certain places.

Concepts:
- Forward Edge (An edge that connects to a non-visited node).
- Back Edge (An edge that connects to a visited node).

Algorithm:

- Maintain two arrays (time and low). Time maintains the time
in which a node is visited in the DFS. Low maintains an connected ancestor
which was visited the "earliest" in the DFS.

*/

int n = 100;
vector<vector<int>> adj(n);

vector<bool> visited(n, false);
vector<int> tin(n, -1), low(n, -1);
int timer = 0;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p)
            continue;
        if (visited[to])
            low[v] = min(low[v], tin[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                printf("Bridge (%i - %i)\n",v,to);
            }
        }
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

    dfs(0);
    for (int i = 0; i < 5; i++) {
        printf("%i - %i\n",i,low[i]);
    }
}
