// C++ Graph Adjacency List Representation
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N = 4; // N = total vertices
    vector<int> adj[N];
    // How to represent V1 -> [V2, etc.]
    adj[1].push_back(2);
    adj[2].push_back(3);

    // adjacency list with weight
    vector<pair<int,int>> adj2[N];
    // Create a edge v1 to v2 with w = 5
    adj2[1].push_back({2,5});

}