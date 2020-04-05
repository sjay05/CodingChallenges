/*===================================
#	Author:		sjay05
#	File:		prim.cpp
#	Desc:		Prim's MST Algorithm
===================================*/
#include <bits/stdc++.h>

using namespace std;

/*
Prim's algorithm is an alternative method 
for finding a minimum spanning tree. It starts
off with choosing arbitrary node to the tree 
and then chooses a minimum-weight edge that 
add's a new node to the tree. The time complexity
of O(n + m log m) equaling the time of Dijkstra's
Algorithm. 
*/

/*
Unlike kruskal, we don't need disjoint set, we
require a priority queue - for efficient applica-
tion. We add all the available edges from the 
queue the take from the top. 
*/

/*
! Right not this program can only find
! the cost of the MST, and not generate 
! an adjacency list itself.
*/

#define Edge pair<int,int>

int MAXN = 100;
vector<vector<pair<int,int>>> adj(MAXN);

void prim(int start) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    bool vis[MAXN];
    for (Edge &e : adj[start]) {
        pq.push(e);
    }
    int cost = 0;
    vis[start] = true;
    while (!pq.empty()) {
        Edge e = pq.top(); pq.pop();
        if (!vis[e.second]) {
            vis[e.second] = true;
            cost += e.first;
            for (Edge &ee : adj[e.second]) {
                pq.push(ee);
            }
        }
    }
    return;
}

int main() {
    int e, u, v, w;
    scanf("%i", &e);
    while (e--) {
        scanf("%i%i%i", &u, &v, &w);
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    prim(1);
}