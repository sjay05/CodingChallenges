#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <typename T>
class bin_lift {
  public:
    int mn, lg, tim = 0;
    vector<vector<int>> anc;
    vector<int> depth;
    vector<int> in, out;

    bin_lift(int _n) : mn(_n) {
      lg = 32 - __builtin_clz(_n);
      anc.reserve(_n);
      anc.resize(_n);
      depth.reserve(_n);
      depth.resize(_n);
      for (int i = 0; i < _n; i++) {
        anc[i].reserve(lg + 1);
        anc[i].assign(lg + 1, -1);
      }
      in.reserve(_n);
      out.reserve(_n);
      in.resize(_n);
      out.resize(_n);
    }

    void dfs(int u, int p, digraph<T> &g) {
      in[u] = ++tim;
      anc[u][0] = p;
      for (int i = 1; i < lg; i++) {
        if (anc[u][i - 1] != -1) {
          anc[u][i] = anc[anc[u][i - 1]][i - 1];
        }
      }
      for (int v : g.g[u]) {
        if (v != p) {
          depth[v] = depth[u] + 1;
          dfs(v, u, g);
        }
      }
      out[u] = ++tim;
    }

    bool ances(int u, int v) {
      if (in[u] <= in[v] && out[u] >= out[v]) {
        return true;
      } else {
        return false;
      }
    }

    int kth_anc(int x, int k) {
      for (int i = lg; i >= 0; i--) {
        if (k & (1 << i)) {
          x = anc[x][i];
        }
      }
      return x;
    }

    int lca(int u, int v) {
      if (ances(u, v)) {
        return u;
      } if (ances(v, u)) {
        return v;
      }
      for (int i = lg; i >= 0; i--) {
        if (!ances(anc[u][i], v) && anc[u][i] != -1) {
          u = anc[u][i];
        }
      }
      return anc[u][0];
    }

    int dist(int a, int b) {
      return depth[a] + depth[b] - 2 * depth[lca(a, b)];
    }

    bool is_on(int u, int v, int x) {
      return dist(u, x) + dist(v, x) == dist(u, v);
    }

    int kth_on_path(int a, int b, int k) {
      int dd = dist(a, b), _lca = lca(a, b);
      if (abs(depth[a] - depth[_lca]) >= k) {
        return kth_anc(a, k);
      } else {
        return kth_anc(b, dd - k);
      }
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  return 0;
}
