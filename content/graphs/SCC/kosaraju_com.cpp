#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

typedef vector<int> vi;

/*
Variables - Definition:

maxn = max number of nodes
n = nodes in input
m = edges in input
u, v = connection from u -> v
graph = initial directed graph
rgraph = transposed graph
comp = component array
det = stack for 1st dfs
*/
const int maxn = 1000005;
int n, m, u, v;
bool vis[maxn];
vector<vi> graph(maxn), rgraph(maxn);
vector<int> comp(maxn);
stack<int> det;

/*
Explanation of dfs(u):
- Standard dfs except add
a node to the stack once you've
visited all the neighbors.
*/
void dfs(int u) {
    vis[u] = true;
    for (int v : graph[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    det.push(u);
}

/*
Mark the current node visited
and indicate which SCC it belongs
in. Iterate over its neighbors
and repeat the process for the
rest of the SCC.
*/
void dfs_2(int u, int ord) {
    vis[u] = true;
    comp[u] = ord;

    for (int v : rgraph[u]) {
        if (!vis[v]) {
            dfs_2(v, ord);
        }
    }
}

/*
Use the graph adjacency list
to generate backwards edges.
*/
void gen_tranpose() {
    for (int i = 0; i <= n; i++) {
        for (int j : graph[i]) {
            rgraph[j].push_back(i);
        }
    }
}

int main() {
    /*
    Process the input and
    mark the visited array
    false.
    */
    scanf("%i%i",&n,&m);
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < m; i++) {
        scanf("%i%i",&u,&v);
        graph[u].push_back(v);
    }

    /*
    Call the 1st dfs for each node.
    */
    for (int i = 0; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    /*
    Generate the transposition of
    the graph and reset the visited
    array to prep for the 2nd dfs.
    */
    gen_tranpose();
    memset(vis, 0, sizeof vis);

    /*
    For any node that just doesn't
    exist in the graph will have a
    comp[u] of -1 so we start with
    an array of -1s.
    */
    comp.assign(n + 1, -1);

    /*
    cnt = the variable maintained
    to indicate which SCC we are
    dfs'ing over.
    */
    int cnt = 0;
    while (!det.empty()) {
        /*
        Graph the node from
        the stack.
        */
        int node = det.top();
        det.pop();
        if (!vis[node]) {
            /*
            Call the dfs_2() func
            with an incrementation
            of cnt.
            */
            dfs_2(node, ++cnt);
        }
    }

    /*
    Indicate which component node (i)
    is in from [0...n] as indicated
    in the input.
    */
    for (int i = 0; i <= n; i++) {
        printf("%i = %i\n",i,comp[i]);
    }
}
