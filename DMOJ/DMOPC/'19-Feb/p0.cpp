#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, C; scanf("%d %d", &N, &C);
  string name; int x;
  while (N--) {
    cin >> name >> x;
    if (x > C) {
      cout << name << " will advance\n";
    } else {
      cout << name << " will not advance\n";
    }
  }
}