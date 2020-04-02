/* --- TOPOLOGICAL SORT --- */
#include <bits/stdc++.h>

using namespace std;

/*
Time Complexity : O(|V| + |E|)
Algorithm:
 When we pick a node and DFS from it, we can find everything that has to
 be completed after it. When a node has no more neighbors, it can be
 pushed to the topological stack and marked. We continue to call DFS on
 all other nodes that haven't been visited and this will produce a topological
 stack.

Sample Graph: (on wikipedia...)
9
5 11
7 11
7 8
3 8
3 10
11 2
11 9
11 10
8 9
 */

const int MAXN = 15;
vector<vector<int>> adj(MAXN);
set<int> nodes;
vector<bool> visited(MAXN, false);
vector<int> ans;

void dfs(int v) {
  visited[v] = true;
  for (int u : adj[v]) {
    if (!visited[u]) {
      dfs(u);
    }
  }
  ans.push_back(v);
}

void topological_sort() {
  for (int i : nodes) {
    if (!visited[i]) {
      dfs(i);
    }
  }
  reverse(ans.begin(), ans.end());
}

int main() {
  int E, A, B;
  scanf("%i", &E);
  while (E--) {
    scanf("%i %i", &A, &B);
    adj[A].push_back(B);
    nodes.insert(A);
    nodes.insert(B);
  }
  topological_sort();
  printf("Topological Sequence: ");
  for (int i : ans) {
    printf("%i ", i);
  }
  printf("\n");
}