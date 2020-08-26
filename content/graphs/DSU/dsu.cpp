#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <typename T>
class dsu {
  public:
    vector<T> id;
    int n;

    dsu(int _n) : n(_n) {
      id.resize(n);
      iota(id.begin(), id.end(), 0);
    }

    int root(int x) {
      while (x != id[x]) {
        id[x] = id[id[x]];
        x = id[x];
      }
      return x;
    }

    void unite(int x, int y) {
      int i = root(x);
      int j = root(y);
      id[i] = j;
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  dsu<int> dt(10);
  dt.unite(1, 4);
  dt.unite(4, 7);
  dt.unite(2, 3);
  dt.unite(3, 8);
  dt.unite(3, 6);

  return 0;
}
