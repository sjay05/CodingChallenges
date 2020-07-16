#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 5;
int n, m, p[maxn], ans[maxn], seg[4 * maxn];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    seg[v] = ans[tl];
  } else {
    int mid = (tl + tr) / 2;
    build(v * 2, tl, mid);
    build(v * 2 + 1, mid + 1, tr);
    seg[v] = seg[v * 2] + seg[v * 2 + 1];
  }
}

int query(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) {
    return seg[v];
  }
  int mid = (tl + tr) / 2;
  int left_v = query(v * 2, tl, mid, l, min(r, mid));
  int right_v = query(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
  return left_v + right_v;
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
    seg[v] = seg[v * 2] + seg[v * 2 + 1];
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  build(1, 0, n - 1);

  for (int i = 0; i < n; i++) {
    int va = p[i];
    if (va == n) {
      cout << 0 << " ";
      update(1, 0, n - 1, n - 1, 1);
      continue;
    }
    int el_c = query(1, 0, n - 1, va, n - 1);
    cout << el_c << " ";
    update(1, 0, n - 1, va - 1, 1);
  }
  cout << "\n";
}
