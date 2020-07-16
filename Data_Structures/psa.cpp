#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct prefix_arr {
  int size;
  vector<int> arr, pfx;

  void init(int sz) {
    size = sz;
    arr.resize(sz);
    pfx.resize(sz);
  }

  void build() {
    for (int i = 0; i < size; i++) {
      if (i == 0) {
        pfx[i] = arr[i];
      } else {
        pfx[i] = arr[i] + pfx[i - 1];
      }
    }
  }

  int query(int l, int r) {
    if (l == 0) {
      return pfx[r];
    } else {
      return pfx[r] - pfx[l - 1];
    }
  }
};

int main() {
  prefix_arr psa;

  psa.init(8);

  int arr[] = {1, 3, 4, 8, 6, 1, 4, 2};
  for (int i = 0; i < 8; i++) {
    psa.arr[i] = arr[i];
  }

  psa.build();
  cout << psa.query(0, 2) << "\n";
}
