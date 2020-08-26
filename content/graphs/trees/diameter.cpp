#include <bits/stdc++.h>

using namespace std;

/*
Finding the Diamter of a Tree (Approach #1):

- This approach uses two dfs searches.

The diameter is the maximal length between two
nodes in a tree.

To find the diameter pick a arbitrary node and
find its farthest node, and then take repeat the process
again from that node. The path generated will be
the diameter of the tree.

Time Complexity: O(|V| + |E|)
*/

// number of edges
const int maxn = 1e5;
// n = number of nodes, u-v (edge)
int n, u, v;
// two variables maintained (max dist so far)
// and (max node so far).
int max_dist, max_node;

void dfs(int node, int parent, int dist) {
    if (dist > max_dist) {
        max_dist = dist, max_node = node;
    }
    for (int v : adj[node]) {
        if (v != parent) {
            dfs(v, node, dist + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, 0);
    dfs(max_node, -1, 0);
    cout << max_dist << "\n";

    /*
    To find the two nodes that make up the diameter
    you must maintain seperate variables in the dfs.
    */
}
