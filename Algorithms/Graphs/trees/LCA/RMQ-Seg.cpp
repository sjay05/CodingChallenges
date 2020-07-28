#include <bits/stdc++.h>

using namespace std;

/*
Description: Given a tree of N verticies, take
Euler tour of the graph (DFS) and compute LCA()
with RMQ using Segment Tree or any other RMQ.
Time:
Segment Tree: O(\log n) query & O(n) build.
Sparse Table: O(n \log n) build & O(1) query.

Source: https://cp-algorithms.com/graph/lca.html
 */

const int MN = 100;
const int TSP = (MN * 2 + 1);

vector<int> euler, first(MN), height(MN);
bool vis[MN];
vector<int> adj[MN];

template <class T> struct Seg {
  /*
  Use ID respective for seg -
  min / max / sum;
  */
  const T ID = INT_MAX;
  int n; vector<T> seg;
  void init(int _n) {
    n = _n;
    seg.assign(4 * n, 0);
  }
  void buildcc(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = euler[tl];
    } else {
        int mid = (tl + tr) / 2;
        buildcc(v * 2, tl, mid);
        buildcc(v * 2 + 1, mid + 1, tr);
        int ll = seg[v * 2];
        int rr = seg[v * 2 + 1];
        seg[v] = (height[ll] < height[rr]) ? ll : rr;
    }
  }

  int querycc(int v, int tl, int tr, int l, int r) {
    if (l > r) {
      return ID;
    } if (tl == tr && r == tr) {
      return seg[v];
    }
    int mid = (tl + tr) / 2;
    int left_v = querycc(v * 2, tl, mid, l, min(r, mid));
    int right_v = querycc(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
    if (left_v == INT_MAX) {
      return right_v;
    } if (right_v == INT_MAX) {
      return left_v;
    }
    return (height[left_v] < height[right_v]) ? left_v : right_v;
  }

  void build() {
    buildcc(1, 0, n - 1);
  }
  int query(int l, int r) {
    return querycc(1, 0, n - 1, l, r);
  }
};
Seg<int> st;

void dfs(int u, int h = 0) {
  vis[u] = true;
  height[u] = h + 1;
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
  adj[1].push_back(2);
  adj[1].push_back(3);
  adj[1].push_back(4);
  adj[2].push_back(5);
  adj[2].push_back(6);
  adj[4].push_back(7);
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
  st.init(TSP);
  dfs(1);
  st.build();
  int dist = height[5] + height[8] - 2 * height[lca(5, 8)];
  cout << lca(4, 4) << "\n";
}
