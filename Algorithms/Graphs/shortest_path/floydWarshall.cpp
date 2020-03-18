#include <bits/stdc++.h>

/*
 * The Floyd-Warshall algorithm is a "All pairs
 * Shortest Paths" finder with a time complexity of
 * O(N^3).
 */

using namespace std;

const int MAXN = 10;
const int INF = 1e7;
int adj[MAXN][MAXN];
int dist[MAXN][MAXN];

void setup(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else if (adj[i][j] != 0)
                dist[i][j] = adj[i][j];
            else
                dist[i][j] = INF;
        }
    }
}

int floyd(int n, int src, int dest)
{
    for (int k = 1; k < n; k++)
        for (int i = 1; i < n; i++)
            for (int j = 1; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    return dist[src][dest];
}

int main()
{
    int E;
    cin >> E;
    int F, T, W;
    while (E--)
    {
        cin >> F >> T >> W;
        adj[F][T] = W;
        adj[T][F] = W;
    }
    setup(MAXN);
    cout << floyd(MAXN, 1, 5) << endl;
}

/*
7
1 2 3
2 4 4
4 3 3
1 3 1
3 6 1
3 5 2
5 6 1
 */