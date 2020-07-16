#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
2 - Dymensional Prefix Sum Array:

Queries sum of square (a, b) -> (c, d).

Implementation Details:
psa[i][j] = psa[i - 1][j] + psa[i][j - 1] -
              psa[i - 1][j - 1] + arr[i][j];

- Make sure the psa is 1-indexed.

Query from (a, b) to (c, d) using inclusion-exclusion:

query(a, b, c, d) = psa[c][d] - psa[a - 1][d] -
                      psa[c][b - 1] + psa[a - 1][b - 1].

Reference:
https://www.geeksforgeeks.org/prefix-sum-2d-array/

Complexity:
For a grid size of (R, C):
Build: O(R * C)
Query: O(1)
Update: O(R * C) - Basically Rebuild PSA
*/

const int maxn = 100;

int r, c, arr[maxn][maxn], psa[maxn][maxn];

void build() {
  psa[1][1] = arr[1][1];

  for (int i = 2; i <= c; i++) {
    psa[1][i] = psa[1][i - 1] + arr[1][i];
  }

  for (int i = 2; i <= r; i++) {
    psa[i][1] = psa[i - 1][1] + arr[i][1];
  }

  for (int i = 2; i <= r; i++) {
    for (int j = 2; j <= c; j++) {
      psa[i][j] = psa[i - 1][j] + psa[i][j - 1] -
                    psa[i - 1][j - 1] + arr[i][j];
    }
  }

#ifdef DEBUG
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cout << psa[i][j] << " ";
    }
    cout << "\n";
  }
#endif
}

int query(int a, int b, int c, int d) {
  return psa[c][d] - psa[a - 1][d] -
          psa[c][b - 1] + psa[a - 1][b - 1];
}

int main() {
  cin >> r >> c;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cin >> arr[i][j];
    }
  }
  build();
  cout << query(2, 2, 4, 4) << "\n";
}

/*
4 5
1 2 3 4 6
5 3 8 1 2
4 6 7 5 5
2 4 8 9 4
*/
