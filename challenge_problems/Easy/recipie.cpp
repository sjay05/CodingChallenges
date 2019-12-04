// Swedish Olympiad in Informatics 2011, School Qualifiers - THE RECIPIE

#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  int total = 0;
  for (int i = 0; i<N; i++) {
    int c, h, n;
    cin >> h >> n >> c;
    if (n > h) {
      total += max(0, n-h)*c;
    }
  }
  cout << total;
}