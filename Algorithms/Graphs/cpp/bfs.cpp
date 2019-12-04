// C++ BFS Graph Traversal
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[6];


void bfs(int x, bool visited[6], int distance[6], queue<int> q) {
    visited[x] = true;
    distance[x] = 0;
    q.push(x);
    cout << x;
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u: adj[s]) {
            cout << u;
            if (visited[u]) continue;
            visited[u] = true;
            distance[u] = distance[s]+1;
            q.push(u);
        }
    }
}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[2].push_back(3);
    adj[2].push_back(5);
    adj[5].push_back(6);
    adj[3].push_back(6);
    bool visited[6];
    int distance[6];
    queue<int> q;
    bfs(1, visited, distance, q);
}