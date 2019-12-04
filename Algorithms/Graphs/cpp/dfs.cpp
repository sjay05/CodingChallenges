// C++ DFS Graph Traversal
#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[5];
bool visited[5];

void dfs(int node) {
    if (visited[node]) return;
    visited[node] = true;
    cout << node << endl;
    for(auto u: adj[node]) {
        dfs(u);
    }

}

int main() {
    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[2].push_back(3);
    adj[2].push_back(5);
    adj[3].push_back(5);
    dfs(1);
}
