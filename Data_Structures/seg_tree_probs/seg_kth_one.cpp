#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100005;
int n, m, arr[maxn], seg[4 * maxn];

int merge(int a, int b) {
  return a + b;
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

int query(int k, int v, int tl, int tr) {
  if (tl == tr) {
    return tl;
  }
  int mid = (tl + tr) / 2;
  int el = seg[v * 2];
  if (k < el) {
    return query(k, v * 2, tl, mid);
  } else {
    return query(k - el, v * 2 + 1, mid + 1, tr);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(1, 0, n - 1);
  int op, i, k;
  while (m--) {
    cin >> op;
    if (op == 1) {
      cin >> i;
      arr[i] = 1 - arr[i];
      update(1, 0, n - 1, i, arr[i]);
    } else {
      cin >> k;
      cout << query(k, 1, 0, n - 1) << "\n";
    }
  }
}
