#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

/*
Compressing SCC's into a DAG:

DAG = directed acyclic graph

- Using either Tarjan's or
Kosaraju's SCC algorithm we can
compress the components into a
single node. This is useful because
the resulting graph doesn't
contain any cycles.

Approach:
- Given an array comp[u], we get
the component node u belongs in.
- Iterate over all the edges, and
for each edge (u -> v), it comp[u]
!= comp[v], we can add this edge
int he compressed graph.

Implementation:
- This implementation uses Kosaraju's
algorithm for SCC's.
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
    /*
    End of Kosaraju's SCC. Next
    step is to generate the DAG.
    */
    int total_comps = cnt;
    vector<vi> dag(n + 1);
    for (int i = 0; i <= n; i++) {
        for (int j : graph[i]) {
            if (comp[i] != comp[j]) {
                dag[comp[i]].push_back(comp[j]);
            }
        }
    }
    for (int i = 1; i <= total_comps; i++) {
        printf("%i = ",i);
        for (int j : dag[i]) {
            printf("%i ",j);
        }
        printf("\n");
    }
}
