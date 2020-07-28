#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
* Description: Euler Tour LCA Queries in O(1)
* with O(N \log N) preprocessing using RMQ
* Sparse Table.
*/

const int MN = 100;
const int TSP = (MN * 2 + 1);

vector<int> euler, first(MN), height(MN);
bool vis[MN];
vector<int> adj[MN];

template <int maxn> struct RMQ {
  int spt[18][maxn];
  int lg[maxn + 5];

  void init() {
    for (int i = 0; i < (int) euler.size(); i++) {
      spt[0][i] = euler[i];
    }
    lg[1] = 0;
    for (int i = 2; i <= maxn; i++) {
      lg[i] = lg[i / 2] + 1;
    }
    for (int j = 0; j < lg[maxn]; j++) {
      for (int i = 0; i + (1 << j) < maxn; i++) {
        int v1 = spt[j][i];
        int v2 = spt[j][i + (1 << j)];
        if (height[v1] < height[v2]) {
          spt[j + 1][i] = spt[j][i];
        } else {
          spt[j + 1][i] = spt[j][i + (1 << j)];
        }
      }
    }
  }
  int query(int l, int r) {
    int k = lg[r - l + 1];
    int v1 = spt[k][l];
    int v2 = spt[k][r - (1 << k) + 1];
    if (height[v1] < height[v2]) {
      return spt[k][l];
    } else {
      return spt[k][r - (1 << k) + 1];
    }
  }
};
RMQ<TSP> st;

void dfs(int u, int h = 0) {
  vis[u] = true;
  height[u] = (h + 1);
  first[u] = (int) euler.size();
  euler.push_back(u);
  for (int v : adj[u]) {
    if (!vis[v]) {
      dfs(v, h + 1);
      euler.push_back(u);
    }
  }
}

void build_tree() {
  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[2].push_back(3);
  adj[2].push_back(4);
  adj[3].push_back(5);
}

int lca(int u, int v) {
  int l = first[u];
  int r = first[v];
  if (l > r) {
    swap(l, r);
  }
  return st.query(l, r);
}

int main() {
  build_tree();
  dfs(0);
  st.init();
  int a = 4, b = 5;
  int dist = height[a] + height[b] - 2 * height[lca(a, b)];
  cout << dist << "\n";
}
