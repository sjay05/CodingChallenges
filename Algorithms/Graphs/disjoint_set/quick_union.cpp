/* QUICK UNION ALGORITHM USING DISJOINT SET */
#include <bits/stdc++.h>

using namespace std;

/*
Using the disjoint-set structure, we can enforce a "lazy"
approach to create union and find. The time-complexity remains
the same for union and is now O(N) for find. Even if it is worse
that quick find, the union can also be used now to do (union & find)
which might be useful in some problems.

Lazy Approach:
Root of id[i] = id[id[id[id[...id[i]...]]]]

Find: check if p and q have the same root.
Union: set p's root to q's root.

Path Compression Optimization:
 - in the root() function we can add
 id[i] = id[id[i]] to make it point straight
 to it's grandparent cutting time by almost a
 half.
*/

#define maxn 10
vector<int> obj;
vector<int> id(maxn+1);

void set_all() {
    for (int i : obj) {
        id[i] = i;
    }
}

int root(int i) {
    while (i != id[i]) {
        // [line 39] - path compression optimization (refer docs)
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

bool find(int p, int q) {
    return root(p) == root(q);
}

void unite(int p, int q) {
    int i = root(p);
    int j = root(q);
    id[i] = j;
}

int main() {
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
    cout << root(3) << "\n";
    // if (find(2, 8)) {
    //     printf("Connected\n");
    // } else {
    //     printf("Not Connected\n");
    // }
}