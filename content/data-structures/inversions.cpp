#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
Counting Inversions:
- Given array a[0...n] count pairs a[i],
a[j] where (i < j) such that a[i] > a[j].

Idea:
Find number of smaller elements for each
value a[i] (1 <= i <= n) using fenwick.
Total number of inversions is sum of counts
for each a[i].

Implementation:
Iterating the array from the right side,
for each element the index in the BIT represents
whether the number is visited or not.

Example:
Array = [8, 4, 2, 1]
Bit = [0, 0, 0, 0, 0, 0, 0, 0]

First el = 1
tot += 0
bit = [1, 0, 0, 0, 0, 0, 0, 0]

Second el = 2
tot += 2
bit = [1, 1, 0, 0, 0, 0, 0, 0]
*/

template <typename T>
class fenwick {
  public:
    vector<T> fenw;
    int n;
    fenwick(int _n) : n(_n) {
      fenw.resize(n);
    }
    void modify(int x, T v) {
      while (x < n) {
        fenw[x] += v;
        x |= (x + 1);
      }
    }
    T get(int x) {
      T v {};
      while (x >= 0) {
        v += fenw[x];
        x = (x & (x + 1)) - 1;
      }
      return v;
    }

    T query(int l, int r) {
      if (l == 1) {
        return get(r);
      } else {
        return get(r) - get(l - 1);
      }
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> arr = {8, 4, 2, 1};
  fenwick<int> ft(*max_element(arr.begin(), arr.end()) + 5);

  long long ans = 0;
  for (int i = (int) arr.size() - 1; i >= 0; i--) {
    ans += ft.get(arr[i] - 1);
    ft.modify(arr[i], 1);
  }
  cout << ans << '\n';
  return 0;
}
