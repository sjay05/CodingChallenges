#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
Bipartite Graph Check:
- Whether you can color the graph with 2-colors
such that neighbors don't have the same color.

Property:
- A graph if bipartite it means all it cycles have
even length.

Simple Proof:
- If the graph is bipartite and has sets V1, V2
of verticies with one set being one color and
the same for the other. Every step is from a node
from V1 -> V2 or V2 -> V1. To end up were you
started - even number of steps in necessary.
We can correlate this to only having (even) cycles.

Implementation:
- Can use DFS or BFS to implementing the simulation
of bipartiteness check.
*/

const int mn = 1e5 + 10;
vector<int> adj[mn];
bool bad, group[mn], vis[mn];

void make_graph() {
  adj[1].push_back(2);
  adj[2].push_back(3);
  adj[3].push_back(5);
  adj[5].push_back(2);
}

void dfs(int u, bool g = 0) {
  vis[u] = true;
  group[u] = g;
  for (int v : adj[u]) {
    if (vis[v] && group[v] == g) {
      bad = true;
    } else {
      dfs(v, !g);
    }
  }
}

void bfs() {
  /*
  Either node can have color (0) and
  color (1).
  */

  vector<int> col(mn, -1);

  auto get_col = [&] (int u) {
    if (col[u] == 0) {
      return 1;
    }
    return 0;
  };

  bool bip = true;
  queue<int> q;
  for (int nd = 0; nd < mn; nd++) {
    if (col[nd] == -1) {
      col[nd] = 0;
      q.push(nd);
      while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
          if (col[u] == -1) {
            col[u] = get_col(v);
            q.push(u);
          } else {
            if (col[u] == col[v]) {
              bip = false;
            }
          }
        }
      }
    }
  }
  if (bip) {
    cout << "true\n";
  } else {
    cout << "false\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  make_graph();
  for (int i = 1; i <= 3; i++) {
    if (!vis[i]) {
      dfs(i, 0);
    }
  }
  if (bad) {
    cout << "false\n";
  } else {
    cout << "true\n";
  }
}
