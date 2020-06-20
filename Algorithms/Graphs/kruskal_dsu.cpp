/*===========================================
|	Author:		sjay05                      |
|	File:		kruskal.cpp                 |
|	Desc:		Krusal's MST Algorithm w/   |
|               DSU Optimization            |
============================================*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

struct ed {
    int u, v, w;
};

/* Constants */
const int MXN = 100;

bool cmp(ed &a, ed &b) {
    return a.w > b.w;
}

vector<int> id(MXN);
vector<ed> adj;

inline int root(int i) {
    while (i != id[i]) {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

inline bool find(int p, int q) {
    return root(p) == root(q);
}

inline void unite(int p, int q) {
    int i = root(p);
    int j = root(q);
    id[i] = j;
}

/*
gen_mst() to return cost of MST.
*/
inline int gen_mst() {
    int _cost = 0;
    for (ed &e : adj) {
        if (root(e.u) != root(e.v)) {
            _cost += e.w;
            unite(e.u, e.v);
        }
    }
    return _cost;
}

int main() {
    int e, u, v, w; scanf("%i",&e);
    for (int i = 0; i < e; i++) {
        scanf("%i%i%i",&u,&v,&w);
        adj.push_back({u, v, w});
    }
    sort(adj.begin(), adj.end(), cmp);
    printf("%i\n",gen_mst());
}