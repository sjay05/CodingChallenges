#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 10;
const int INF = 1e7;
vector<vector<pair<int, int>>> adj(MAXN);

int dijkstra(int src, int dest)
{
    queue<pair<int, int>> buf;
    vector<int> dist(MAXN, INF);
    dist[src] = 0;
    buf.push({0, src});
    while (!buf.empty())
    {
        int v = buf.front().second;
        buf.pop();
        for (auto u : adj[v])
        {
            int node = u.first;
            int weight = u.second;
            if (dist[v] + weight < dist[node])
            {
                dist[node] = dist[v] + weight;
                buf.push({dist[node], node});
            }
        }
    }
    return dist[dest];
}

int main()
{
    int E;
    cin >> E;
    int F, T, W;
    while (E--)
    {
        cin >> F >> T >> W;
        adj[F].push_back({T, W});
        adj[T].push_back({F, W});
    }
    cout << dijkstra(1, 6) << endl;
}