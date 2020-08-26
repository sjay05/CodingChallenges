#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <typename T>
class weighted_graph {
  public:
    struct mst_edge {
      int from, to;
      T weight;
    };
    struct ed {
      int to; T cost;
    };
    vector<vector<ed>> g;
    vector<mst_edge> edges;
    int n;

    weighted_graph(int _n) : n(_n) {
      g.resize(n);
    }

    void add(int from, int to, T cost, bool mst = false) {
      g[from].push_back({to, cost});
      g[to].push_back({from, cost});
      if (mst == true) {
        edges.push_back({from, to, cost});
      }
    }
};

template <typename T>
vector <T> dijkstra(int start, weighted_graph<T> &g) {
  const T _inf = numeric_limits<T>::max();
  vector<T> dist(g.n, _inf);
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
  dist[start] = 0;
  q.emplace(0, start);
  while (!q.empty()) {
    int v = q.top().second;
    int sc = q.top().first;
    q.pop();
    if (dist[v] != sc) {
      continue;
    }
    for (auto x : g.g[v]) {
      int nd = x.to;
      int we = x.cost;
      if (dist[v] + we < dist[nd]) {
        dist[nd] = dist[v] + we;
        q.emplace(dist[nd], nd);
      }
    }
  }
  return dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  weighted_graph<ll> g(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g.add(u, v, w);
  }
  const ll chk = numeric_limits<ll>::max();
  vector<ll> d = dijkstra<ll>(1, g);
  for (int i = 1; i <= n; i++) {
    if (d[i] == chk) {
      cout << -1 << '\n';
    } else {
      cout << d[i] << '\n';
    }
  }
  return 0;
}
