#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
Polynomial Hash for String Matching:
- Used in Rabin-Karp Algorithm.
Usage:
- Set hash value of any substring
given s[a...b] in O(1) time with O(N)
preprocessing.

Generated using https://usaco-guide.vercel.app/CPH.pdf#page=255

For rounds generate base and use 972663749 as mod.

Terms:
h[i] = hash of substring s[0...i]
p[k] = value of base ^ k mod p

Note:
get(i, j) is inclusive (i) and (j)
*/

const ll mod = 972663749;
const ll base = 31;

struct PolyHash {
  vector<ll> p, h;

  void init(string s) {
    p.resize(s.size() + 1);
    h.resize(s.size() + 1);
    p[0] = 1;
    int n = (int) s.size();
    for (int i = 1; i <= n; i++) {
      p[i] = p[i - 1] * base % mod;
    }
    h[0] = s[0] - 'a' + 1;
    for (int i = 1; i < n; i++) {
      h[i] = (h[i - 1] * base % mod + (s[i] - 'a' + 1)) % mod;
    }
  }

  ll get(int i, int j) {
    if (i == 0) {
      return h[j];
    } else {
      return (h[j] - h[i - 1] * p[j - (i - 1)] % mod + mod) % mod;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  PolyHash pt;
  pt.init("abcd");
  cout << pt.get(0, 1) << "\n";
  PolyHash gt;
  gt.init("bacd");
  cout << gt.get(0, 1) << "\n";
}
