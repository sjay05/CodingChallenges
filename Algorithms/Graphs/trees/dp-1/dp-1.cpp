#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int maxn = 100;
int n, m, u, v, x, y, dp[maxn], val[maxn];
vector<vi> adj(maxn);

void dfs(int u, int p) {
    dp[u] = val[u];
    int ma = 0;
    for (int v : adj[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        ma = max(ma, dp[v]);
    }
    dp[u] += ma;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    scanf("%i%i",&n,&m);
    for (int i = 0; i < m; i++) {
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        scanf("%i%i",&x,&y);
        val[x] = y;
    }
    dfs(1, -1);
    printf("%i\n",dp[1]);
	for (int i = 0; i < 10; i++) {
		int x; cin >> x;
	}
}

/*
Official Test Data:

(You can see the pictoral graph in IMG-1.png)

14 13
1 3
3 7
7 14
7 13
1 2
2 5
5 11
5 12
2 6
1 4
4 8
4 9
4 10
1 3
2 2
3 1
4 10
5 1
6 3
7 9
8 1
9 5
10 3
11 4
12 5
13 9
14 8
*/
