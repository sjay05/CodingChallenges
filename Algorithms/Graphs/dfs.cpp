/* --- DEPTH FIRST SEARCH --- */
#include <bits/stdc++.h>

using namespace std;

/*
Time Complexity is O(V + E).
Applications:
 1) Topological Sorting
 2) Finding connected components
 3) Finding articulation points
 4) Finding strongly connected components
 5) Solving puzzles such as mazes

Sample Graph:
5
1 2
1 4
2 3
3 4
4 5
 */

const int MAXN = 100;
vector<vector<int>> adj(MAXN);

vector<bool> visited(MAXN);
void dfs(int v) {
    visited[v] = true;
    for (auto &u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int main() {
    int E, A, B;
    scanf("%i", &E);
    while (E--) {
        scanf("%i %i", &A, &B);
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    dfs(1);
    printf("%s\n", visited[5] ? "Visited." : "Not Visited.");
}