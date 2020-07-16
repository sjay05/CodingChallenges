#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
Segment Tree to find a sub-segment
within the array with maxmimal sum.
*/

struct item {
  ll seg, pref, suf, sum;
};

const int maxn = 100005;
int n, m, arr[maxn];
item seg[4 * maxn];

item merge(item a, item b) {
  return (item) {
    max(a.seg, max(b.seg, a.suf + b.pref)),
    max(a.pref, a.sum + b.pref),
    max(b.suf, b.sum + a.suf),
    a.sum + b.sum
  };
}

item merge_single(int v) {
  if (v > 0) {
    return (item) {v, v, v, v};
  } else {
    return (item) {0, 0, 0, v};
  }
}

void build(int v, int tl, int tr) {
  if (tl == tr) {
    seg[v] = merge_single(arr[tl]);
  } else {
    int mid = (tl + tr) / 2;
    build(v * 2, tl, mid);
    build(v * 2 + 1, mid + 1, tr);
    seg[v] = merge(seg[v * 2], seg[v * 2 + 1]);
  }
}

item query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
      return (item) {0, 0, 0, 0};
    }
    if (l == tl && r == tr) {
      return seg[v];
    }
    int mid = (tl + tr) / 2;
    item left_v = query(v * 2, tl, mid, l, min(r, mid));
    item right_v = query(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
    return merge(left_v, right_v);
}

void update(int v, int tl, int tr, int pos, int new_v) {
  if (tl == tr) {
    seg[v] = merge_single(new_v);
    return;
  }
  int mid = (tl + tr) / 2;
  if (pos <= mid) {
    update(v * 2, tl, mid, pos, new_v);
  } else {
    update(v * 2 + 1, mid + 1, tr, pos, new_v);
  }
  seg[v] = merge(seg[v * 2], seg[v * 2 + 1]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(1, 0, n - 1);
  cout << query(1, 0, n - 1, 0, n - 1).seg << "\n";
  while (m--) {
    int a, b;
    cin >> a >> b;
    update(1, 0, n - 1, a, b);
    cout << query(1, 0, n - 1, 0, n - 1).seg << "\n";
  }
}
