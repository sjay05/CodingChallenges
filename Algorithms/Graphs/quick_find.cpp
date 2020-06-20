/* QUICK-FIND ALGORITHM USING DISJOINT SET */
#include <bits/stdc++.h>

using namespace std;

/*
A disjoint-set structure is a data structure that maintains
a "disjoint" set of element such that an element doesn't exist
within two sets. A quick-find consists of two operations on 
the disjoint set to check if two elements are connected in O(1)
time. There isn't a optmization to the union command however.

Union - connect two objects
find - is there a path between a and b?
*/

#define maxn 10
vector<int> obj;
vector<int> id(maxn+1);

void set_all() {
    for (int i : obj) {
        id[i] = i;
    }
}

bool find(int p, int q) {
    return id[p] == id[q];
}

void unite(int p, int q) {
    int pid = id[p], qid = id[q];
    for (int i : obj) {
        if (id[i] == pid) {
            id[i] = qid;
        }
    }
}

int main() {
    // add nodes [1...10]
    for (int i = 1; i <= maxn; i++) {
        obj.push_back(i);
    }
    set_all();
    /*
    Input Example:
    {1, 4, 7}, {5}, {2, 3, 6, 8};
    */
    unite(1, 4); unite(4, 7);
    unite(2, 3); unite(3, 6);
    unite(3, 8);
    if (find(2, 1)) {
        printf("Connected\n");
    } else {
        printf("Not Connected\n");
    }
}