#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int maxn = 1000005;
vector<vi> graph(maxn);
int n, m, u, v, cnt = 0, cmp_sz = 0,
    low[maxn], tin[maxn];
bool vis[maxn];
stack<int> det;
vector<int> comp(maxn, -1);

void tarj_scc(int u) {
    tin[u] = low[u] = ++cnt;
    vis[u] = true;
    det.push(u);

    for (int v : graph[u]) {
        if (tin[v] == -1) {
            tarj_scc(v);
            low[u] = min(low[u], low[v]);
        } else if (vis[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }
    if (tin[u] == low[u]) {
        ++cmp_sz;
        while (det.top() != u) {
            int n = det.top();
            det.pop();
            vis[n] = false;
            comp[n] = cmp_sz;
        }
        int n = det.top();
        det.pop();
        comp[n] = cmp_sz;
        vis[n] = false;
    }
}

int main()
{
    scanf("%i%i",&n,&m);
    for (int i = 0; i < m; i++) {
        scanf("%i%i",&u,&v);
        graph[u].push_back(v);
    }
    memset(low, -1, sizeof low);
    memset(tin, -1, sizeof tin);
    memset(vis, 0, sizeof vis);

    for (int i = 0; i <= n; i++) {
        if (tin[i] == -1) {
            tarj_scc(i);
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
0 = 1
1 = 1
2 = 1
3 = 2
4 = 3
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
0 = 1
1 = 1
2 = 1
3 = 1
4 = 3
5 = 3
6 = 3
7 = 2
8 = 4
*/
