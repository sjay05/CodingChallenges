#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
Bitmask Dynamic Programming:
- Quick tricks and tips...

- Bitmask stores booleans (whether number (i) was
choosen or not. Instead of using a big boolean
array of map<int,bool> we can represent a maximal
numbers from [1...n] with a number of 1 << n a.k.a
2^n.

Lets say we want to represent [1....25] as
bitmask.

1) The bitmask msk = (1 << 25).

Lets set number (2) a.k.a position 2 to 1.
Right now all positions are 0. This will only
work if the position is already 0.

2) msk |= (1 << 2).

Lets set number (2) position 2, from 1 to 0.
Only work if already 1.

3) msk &= ~(1 << 2).

To check if the (i'th) position is 1 or 0,
we do:

4) msk & (1 << pos)

To toggle the bit (whether 0 -> 1) or (1 -> 0).

5) msk ^= (1 << pos);

To iterate of all subsets of size (n).

for (int msk = 0; msk < (1 << n); msk++) {
  // code
}

*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int dp[x] = dp[x = 1]
}
