#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
Given an array with size n and m queries
with two operations:

1) update(i, v) update i'th element to v
2) sum(l, r) what is the min of elements
    from [l...r - 1] and how many times
    does it appear.

Solution:

For each node you must maintain two points:

1) What is the minimum element in the range
    it covers...
2) How many times does this minimum element
    appear in that range.

When doing our update, rmq, and build operations
we will be comparing nodes and how to do something
with them like min(u, v) or max(u, v) or sum(u, v).

Here we are doing for the minimum element but with
an additional counter value.

Suppose the two nodes we are comparing are (a) and (b).

Logic:
if (a.min_el < b.min_el) {
  return {a.min_el, a.count}
} if (b.min_el < a.min_el) {
  return {b.min_el, b.count}
} else {
  // both are equal so sum up the count
  return {a.min_el, a.count + b.count}
}

This way the information stored int the node will
be correct and can be done in constant time.
*/

struct item {
  int mi, c;

  void print() {
    cout << mi << " " << c << "\n";
  }
};

const int maxn = 100005;
int n, m, arr[maxn];
item seg[4 * maxn];

item merge(item a, item b) {
  if (a.mi < b.mi) {
    return a;
  } if (a.mi > b.mi) {
    return b;
  }
  return (item) {a.mi, a.c + b.c};1
}

void build(int v, int tl, int tr) {
  if (tl == tr) {
    seg[v] = (item) {arr[tl], 1};
  } else {
    int mid = (tl + tr) / 2;
    build(v * 2, tl, mid);
    build(v * 2 + 1, mid + 1, tr);
    seg[v] = merge(seg[v * 2], seg[v * 2 + 1]);
  }
}

item rmq(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return (item) {INT_MAX, 0};
    }
    if (l == tl && r == tr) {
        return seg[v];
    }
    int mid = (tl + tr) / 2;
    item left_v = rmq(v * 2, tl, mid, l, min(r, mid));
    item right_v = rmq(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
    return merge(left_v, right_v);
}

void update(int v, int tl, int tr, int pos, int new_v) {
  if (tl == tr) {
    seg[v] = (item) {new_v, 1};
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
      item res = rmq(1, 0, n - 1, a, b - 1);
      res.print();
    }
  }
}
