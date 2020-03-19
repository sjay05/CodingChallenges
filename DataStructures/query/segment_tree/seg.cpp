/* Single Element Modification Segment Tree */
#include <bits/stdc++.h>

using namespace std;

/*
Below is an non-recursive implementation of "single element 
modification" segment tree. The code can be modified to do range 
[min, max, and sum]. Bitmask can be used at certain locations 
to speed up operations. For example to multiple a number (x) 
by 2, we can do (x << 1) as it represents x * (2^1) = x * 2.
Also, (x /= 2) can be rewritten as (x >>= 1). Finally, to check 
if x is odd, instead of doing (x % 2 == 1) we can do (x & 1).

Time Complexities:
Update = O(log n) 
Range Query = O(log n)

The segment tree is constructed with 2*N size, N being
the size of your array. The first index of the segment 
tree is ignored. Here the following properties to represent
the segment tree as an array. Since every node in the tree
has a left and right child, the parent of tree[k] is tree[k/2].
For parent node (tree[k]), it's children are tree[2k] and 
tree[2k+1]. Below, is a detailed explanation of each operation.

Build() {
    - We are generating the nodes of the tree backwards.
    Staring with the leaf nodes, in this case the min() of 
    it's left and right node is calculated and assigned
    to idx. It is done such that for any node, it's children
    have already been calculated.
}

Update() {
    - Update is a simple operation. For each node, its parent
    has to be updated and so on. The parent can be calculated
    with one of the properties - (dividing the idx by 2). After
    the (log n) parent's are updated, the seg tree is updated.
}

Sum() {
    - Sum is one of the more difficult operations. We follow
    the concept that as soon as a node becomes a right-child,
    it is useless to go the parent, so we min() it with a global
    variable. A node can be checked if it is a right child, as
    all right child idx's are odd. 
}
*/

#define _min(a, b) a < b ? a : b

int n = 8;
vector<int> arr = {1, 5, 3, 7, 3, 6, 5, 7};
vector<int> seg(2*n);

void build() {
    copy(arr.begin(), arr.end(), &seg[0]+n);
    for (int idx = n-1; idx > 0; idx--) {
        seg[idx] = min(seg[idx*2], seg[idx*2+1]);
    }
}

void update(int idx, int val) {
    idx += n;
    seg[idx] = val;
    while (idx > 1) {
        idx /= 2;
        seg[idx] = min(seg[2*idx], seg[2*idx+1]);
    }
}

// Range = [l, r) - (idx r is not included)
int min(int l, int r) {
    int ret = INT_MAX;
    l += n; r += n;
    while (l < r) {
        if (l % 2 == 1) {
            ret = _min(ret, seg[l]);
            l++;
        } 
        if (r % 2 == 1) {
            r--;
            ret = _min(ret, seg[r]);
        }
        l /= 2; r /= 2;
    }
    return ret;
}

int main() {
    build();
    printf("%i\n", min(3, 8));
}