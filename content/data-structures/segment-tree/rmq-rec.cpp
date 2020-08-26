#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
Segment Tree Implementation For Range Max/Min Query.
- In this case it will be min query.
*/

const int maxn = 6;
int arr[] = {2, 5, 1, 4, 9, 3};
int seg[4 * maxn];

/*
v -> index of vertex
tl, tl -> boundaries of vertex
*/
void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = arr[tl];
    } else {
        int mid = (tl + tr) / 2;
        build(v * 2, tl, mid);
        build(v * 2 + 1, mid + 1, tr);
        seg[v] = min(seg[v * 2], seg[v * 2 + 1]);
    }
}

int rmq(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return INT_MAX;
    }
    if (l == tl && r == tr) {
        return seg[v];
    }
    int mid = (tl + tr) / 2;
    int left_v = rmq(v * 2, tl, mid, l, min(r, mid));
    int right_v = rmq(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
    return min(left_v, right_v);
}

void update(int v, int tl, int tr, int pos, int new_v) {
    if (tl == tr) {
        seg[v] = new_v;
    } else {
        int mid = (tl + tr) / 2;
        if (pos <= mid) {
            update(v * 2, tl, mid, pos, new_v);
        } else {
            update(v * 2 + 1, mid + 1, tr, pos, new_v);
        }
        seg[v] = min(seg[v * 2], seg[v * 2 + 1]);
    }
}

int main() {
    build(1, 0, maxn - 1);
    update(1, 0, maxn - 1, 2, 10);
    cout << rmq(1, 0, maxn - 1, 1, 5) << "\n";
}
