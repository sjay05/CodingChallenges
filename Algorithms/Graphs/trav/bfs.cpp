/* --- BREADTH FIRST SEARCH --- */
#include <bits/stdc++.h>

using namespace std;

/*
Time Complexity is O(V + E).
Applications:
 1) Finding all connected components in graph
 2) Finding all nodes within one connected component
 3) Finding the shortest path between two nodes
 4) Testing a graph for bipartite.

We will be implementing 2 different kinds of BFS, one
 is just traversal, and the other is distance oriented.

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

// Normal bfs trav to find if src connected to dest
bool bfs(int src, int dest)
{
    vector<bool> visited(MAXN);
    queue<int> buf;
    visited[src] = true;
    buf.push(src);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &x : adj[u])
        {
            if (!visited[x])
            {
                buf.push(x);
                visited[x] = true;
            }
        }
    }
    return visited[dest];
}

// One way to find shortest path using INT_MAX in dist vector.
int bfs2(int src, int dest)
{
    vector<int> dist(MAXN, INT_MAX);
    queue<int> buf;
    buf.push(src);
    dist[src] = 0;
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &x : adj[u])
        {
            if (dist[u] + 1 < dist[x])
            {
                dist[x] = dist[u] + 1;
                buf.push(x);
            }
        }
    }
    return dist[dest];
}

// Another way to find shortest path keeping dist vector at 0
int bfs3(int src, int dest)
{
    vector<int> dist(MAXN, 0);
    queue<int> buf;
    buf.push(src);
    while (!buf.empty())
    {
        int u = buf.front();
        buf.pop();
        for (auto &v : adj[u])
        {
            if (!dist[v])
            {
                dist[v] = dist[u] + 1;
                buf.push(v);
            }
        }
    }
    return dist[dest];
}

int main()
{
    int E, A, B;
    scanf("%i", &E);
    while (E--)
    {
        scanf("%i %i", &A, &B);
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    printf("%s\n", bfs(1, 6) ? "Visited." : "Not Visited.");
    printf("%i\n", bfs2(1, 4));
    printf("%i\n", bfs3(1, 3));
}
