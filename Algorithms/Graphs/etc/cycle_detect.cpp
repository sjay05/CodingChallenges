/* --- CYCLE DETECTION --- */
#include <bits/stdc++.h>

using namespace std;

/*
Given ADJ LIST as graph representation, find if the graph
is acyclic or not.

We can use DFS. Once we initialize DFS, and maintain a "cycle
stack". If we visit a node that has already been pushed to the stack,
it means we found a cycle.
*/

#define all(x) x.begin(), x.end()
#define found(i, x) find(all(x), i) != x.end()

const int MAXN = 5;
vector<vector<int>> adj(MAXN);
vector<bool> visited(MAXN);

bool cycle_detect(vector<int> cs, int n) {
  if (found(n, cs)) {
    return true;
  } else if (visited[n]) {
    return false;
  } else {
    bool exist = false;
    for (int i : adj[n]) {
      exist = true;
      break;
    }

    if (exist) {
      cs.push_back(n);
      visited[n] = true;
      for (int i : adj[n])
        if (cycle_detect(cs, i)) return true;
    }
  }
  return false;
}

int main() {
  adj[1].push_back(2);
  adj[2].push_back(3);
  adj[3].push_back(1);
  printf("%s\n", cycle_detect({}, 1) ? "Cycle" : "No Cycle");
}