/*======================================
#	Author:		sjay05
#	File:		kruskal.cpp
#	Desc:		Krusal's MST Algorithm 
=======================================*/
#include <bits/stdc++.h>

using namespace std;

/*
Kruskal's Algorithm starts off with a tree 
with only nodes (no edges). The algorithm goes
through the edges ordered by weights, and adds
it to the graph if it doesn't form a cycle - 
essentially to follow the rules of spanning trees.
*/

/*
This approach implements an algorithm with 
time complexity of O(M log M + N^2). Sorting
the edges requires O(M log M), and information
about where 2 verticies are located is located
in (id[]), and it can be checked if 2 vertex's
have same id in O(1). Now however, to union 
the two edges, we must carry out a O(N) operation.
*/

/*
To speed things up we can use the disjoint
set data structure with O(log n) find and
union. Here is the commented code for it:


*int id[100];

*int root(int i) {
*    while (i != id[i]) {
*        id[i] = id[id[i]];
*        i = id[i];
*    }
*    return i;
*}
*
*bool find(int p, int q) {
*    return root(p) == root(q);
*}
*
*void unite(int p, int q) {
*    int i = root(p);
*    int j = root(q);
*    id[i] = j;
*}

In problems, we tend to prefer Kruskal's implementation
with disjoint-set data structure to avoid TLE at all
costs. 
*/

#define adj_list vector<vector<int>> 

struct Edge {
    int u, v, weight;
};

bool cmp(Edge &x, Edge &y) {
    return x.weight < y.weight;
}

int MAXN = 100;
set<int> vert;
vector<Edge> edges;

adj_list gen_MST() {
    vector<vector<int>> adj(MAXN);
    vector<int> id(MAXN);
    for (int i : vert) 
        id[i] = i;
    sort(edges.begin(), edges.end(), cmp);
    for (Edge &e : edges) {
        if (id[e.u] != id[e.v]) {
            adj[e.u].push_back(e.v);
            adj[e.v].push_back(e.u);

            int pid = id[e.u], qid = id[e.v];
            for (int i : vert) 
                if (id[i] == pid) 
                    id[i] = qid;
        }
    }
    return adj;
}

int main() {
    int E, U, V, W; 
    scanf("%i", &E);
    while (E--) {
        scanf("%i%i%i", &U, &V, &W);
        edges.push_back({U, V, W});
        vert.insert(U); vert.insert(V);
    }
    vector<vector<int>> adj = gen_MST();
    for (int i : vert) {
        printf("%i's neighbors = ", i);
        for (int x : adj[i]) {
            printf("%i ", x);
        }
        printf("\n");
    }
}

/*
Sample Input:
8
1 2 3
1 5 5 
2 5 6
2 3 5
5 6 2 
3 6 3
3 4 9
6 4 7
*/

/*
Sample Ouput for ^ input:
1's neighbors = 2 5 
2's neighbors = 1 
3's neighbors = 6 
4's neighbors = 6 
5's neighbors = 6 1 
6's neighbors = 5 3 4 
*/
