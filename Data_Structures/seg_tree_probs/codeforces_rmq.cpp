#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100005;
int n, m, x;
ll arr[maxn], seg[4 * maxn];

/*
Given an array with size (n) and (m) queries
with two operations:

1) update(i, v) update i'th element to v
2) sum(l, r) what is the min of the elements
    from [l...r - 1]

The solution uses recursive segment tree
with 4*N memory and O(log n) point update
and O(log n) range queries.
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

ll rmq(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return INT_MAX;
    }
    if (l == tl && r == tr) {
        return seg[v];
    }
    int mid = (tl + tr) / 2;
    ll left_v = rmq(v * 2, tl, mid, l, min(r, mid));
    ll right_v = rmq(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
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
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(1, 0, n - 1);
  for (int i = 0; i < m; i++) {
    int op, a, b;
    cin >> op >> a >> b;
    if (op == 1) {
      update(1, 0, n - 1, a, b);
    } else {
      ll res = rmq(1, 0, n - 1, a, b - 1);
      cout << res << "\n";
    }
  }
}
