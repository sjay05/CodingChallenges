#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

/*
Finding the Strongly Connected Components using
Kosaraju's Algorithm:

- Uses 2 DFS searches = O(V + E)

A strongly connected component is a subgraph
such that there is a path between all pairs
of verticies.

Approach:
1) Create a adjacency list to store your
graph with nodes up to (n) and (m) edges.
2) Call dfs on each node and add to stack
when each dfs call has visited all its
neighbors.
3) Create a tranpose graph of the original.
If edge 1 points to 2, in the transpose 2
will point to 1.
4) Reset the visited array.
5) Start popping nodes in the stack
and for each node call dfs. All neighbors
visited will exist int the same SCC.

Outcome:
A comp vector to indicate which component
node n is is in.
Usage: comp[n]

Commented code on kosaraju_com.cpp...
*/

typedef vector<int> vi;

const int maxn = 1000005;
int n, m, u, v;
bool vis[maxn];
vector<vi> graph(maxn), rgraph(maxn);
vector<int> comp(maxn);
stack<int> det;

void dfs(int u) {
    vis[u] = true;
    for (int v : graph[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    det.push(u);
}

void dfs_2(int u, int ord) {
    vis[u] = true;
    comp[u] = ord;

    for (int v : rgraph[u]) {
        if (!vis[v]) {
            dfs_2(v, ord);
        }
    }
}

void gen_tranpose() {
    for (int i = 0; i <= n; i++) {
        for (int j : graph[i]) {
            rgraph[j].push_back(i);
        }
    }
}

int main()
{
    scanf("%i%i",&n,&m);

    memset(vis, 0, sizeof vis);
    for (int i = 0; i < m; i++) {
        scanf("%i%i",&u,&v);
        graph[u].push_back(v);
    }

    for (int i = 0; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    gen_tranpose();
    memset(vis, 0, sizeof vis);

    comp.assign(n + 1, -1);
    int cnt = 0;
    while (!det.empty()) {
        int node = det.top();
        det.pop();
        if (!vis[node]) {
            dfs_2(node, ++cnt);
        }
    }
    for (int i = 0; i <= n; i++) {
        printf("%i = %i\n",i,comp[i]);
    }
}

/*
Test Input #1:
4 5
1 2
0 1
2 0
3 0
4 3

Expected:
0 = 3
1 = 3
2 = 3
3 = 2
4 = 1
*/

/*
Test Input #2:
8 10
1 0
0 3
3 2
2 1
4 2
5 4
6 5
4 6
6 7
8 7

Expected:
0 = 4
1 = 4
2 = 4
3 = 4
4 = 2
5 = 2
6 = 2
7 = 3
8 = 1
*/
