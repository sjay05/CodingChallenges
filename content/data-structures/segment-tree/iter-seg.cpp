#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
Iterative Segment Tree:

- Single element modification
- Range sum query
*/

const int n = 8;
int seg[2 * n];

void build() {
  /*
  Make sure that the array is copied
  at the bottom of the seg tree. The
  array will start at (n + 1).
  */

  for (int i = n - 1; i > 0; i--) {
    seg[i] = seg[2 * i] + seg[2 * i + 1];
  }
}

void update(int p, int v) {
  p += n;
  seg[p] = v;
  while (p > 1) {
    p /= 2;
    seg[p] = seg[2 * p] + seg[2 * p + 1];
  }
}

int query(int l, int r) {
  /*
  Range sum query for [l..r). So
  (r - 1) is not included in the
  range.
  */
  int res = 0;
  l += n, r += n;
  while (l < r) {
    if (l & 1) {
      res += seg[l];
      l++;
    }
    if (r & 1) {
      r--;
      res += seg[r];
    }
    l /= 2, r /= 2;
  }
  return res;
}

/*
5 8 6 3 2 7 2 6
*/

int main() {
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    seg[i + n] = x;
  }
  build();
  cout << query(2, 6) << "\n";
}
