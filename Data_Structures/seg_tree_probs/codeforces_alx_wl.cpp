#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
First Element Which is At Least (X),
also such that it exists after or
including index (l).
*/

const int maxn = 100005;
int n, m, arr[maxn], seg[4 * maxn];

int merge(int a, int b) {
  return max(a, b);
}

int merge_single(int v) {
  return v;
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

int query(int v, int tl, int tr, int x, int l) {
  if (seg[v] < x || tr < l) {
    return -1;
  }
  if (tl == tr) {
    return tl;
  }
  int mid = (tl + tr) / 2;
  int ans = query(v * 2, tl, mid, x, l);
  if (ans == -1) {
    ans = query(v * 2 + 1, mid + 1, tr, x, l);
  }
  return ans;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(1, 0, n - 1);
  while (m--) {
    int op; cin >> op;
    if (op == 1) {
      int i, v;
      cin >> i >> v;
      update(1, 0, n - 1, i, v);
    } else {
      int x, l;
      cin >> x >> l;
      cout << query(1, 0, n - 1, x, l) << "\n";
    }
  }
}
