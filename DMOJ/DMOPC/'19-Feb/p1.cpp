#include <bits/stdc++.h>

using namespace std;

#define str string
#define all(x) (x.begin(), x.end())

int main() {
  int N, M;
  cin >> N >> M;
  vector<str> ing;
  str i;
  while (N--) {
    cin >> i;
    ing.push_back(i);
  }

  int T; str ii;
  int ans = 0;
  while (M--)
  {
    cin >> T;
    bool state = true;
    while (T--)
    {
      cin >> ii;
      if (find(all(ing), ii) == ing.end())
      {
        state = false;
      }
    }
    if (state == true) {
      ans++;
    }
  }
  cout << ans << endl;
}