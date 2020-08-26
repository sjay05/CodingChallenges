#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/* More Includes ... */

template <typename T>
class rmq_lca {
  public:
    int n, tsp;
    bool init_spt = false;
    vector<int> euler, height, first;
    vector<bool> vis;
    SparseTable<int> st;

    function<int(int,int)> cmp = [&] (int a, int b) {
      if (height[a] < height[b]) {
        return a;
      } else {
        return b;
      }
    };

    rmq_lca(int _n) : n(_n) {
      tsp = (T) 2 * n + 1;
      height.reserve(n);
      height.resize(n);
      vis.reserve(n);
      vis.resize(n);
      first.reserve(n);
      first.resize(n);
      st.init_func(cmp);
    }

    void dfs(int u, int h, digraph<T> &g) {
      vis[u] = true;
      height[u] = h + 1;
      first[u] = (int) euler.size();
      euler.push_back(u);
      for (int v : g.g[u]) {
        if (!vis[v]) {
          dfs(v, h + 1, g);
          euler.push_back(u);
        }
      }
    }

    int lca(int u, int v) {
      if (!init_spt) {
        st.init(euler);
        init_spt = true;
      }
      int l = first[u];
      int r = first[v];
      if (l > r) {
        swap(l, r);
      }
      return st.get(l, r);
    }

    int dist(int a, int b) {
      return height[a] + height[b] - 2 * height[lca(a, b)];
    }

    bool is_on(int u, int v, int x) {
      return dist(u, x) + dist(v, x) == dist(u, v);
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
}
