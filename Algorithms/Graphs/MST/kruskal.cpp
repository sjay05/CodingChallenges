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
To speed things up we can use a Disjoint Set Union
to answer find and execute union in O(log n), making
things faster.
*/

#define adj_list vector<vector<int>> 

struct Edge {
    int u, v, weight;
};

bool cmp(Edge &x, Edge &y) {
    return x.weight < y.weight;
}

// total number of nodes
int MAXN = 100;
// set of verticies
set<int> vert;
// edge list
vector<Edge> edges;

adj_list gen_MST() {
    // returns adj_list
    vector<vector<int>> adj(MAXN);
    // id array for connected components
    vector<int> id(MAXN);
    // set all vertex to their own component
    for (int i : vert) 
        id[i] = i;
    // sort edges by weight
    sort(edges.begin(), edges.end(), cmp);
    // traverse edges by sort
    for (Edge &e : edges) {
        /* if both nodes belong to diff component
           then create a connection, and union both
           edges in O(N). */ 
        if (id[e.u] != id[e.v]) {
            // make bi-directional edge
            adj[e.u].push_back(e.v);
            adj[e.v].push_back(e.u);

            // O(N) union of two nodes
            int pid = id[e.u], qid = id[e.v];
            for (int i : vert) 
                if (id[i] == pid) 
                    id[i] = qid;
        }
    }
    // return adj_list
    return adj;
}

int main() {
    int E, U, V, W; cin >> E;
    while (E--) {
        cin >> U >> V >> W;
        edges.push_back({U, V, W});
        // add nodes to set<int> vert
        vert.insert(U); vert.insert(V);
    }
    // get adj_list from get_MST();
    vector<vector<int>> adj = gen_MST();
    // interactive loop to view tree
    for (int i : vert) {
        cout << i << "'s neighbors = ";
        for (int x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
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
