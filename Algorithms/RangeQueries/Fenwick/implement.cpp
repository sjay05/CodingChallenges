/*
Binary Indexed Tree / Fenwick Tree:
update = O(log n)
query = O(log n)

Link = https://cses.fi/book/book.pdf
*/

#include <bits/stdc++.h>

using namespace std;

const int n = 9;
int arr[n] = {0, 1, 3, 4, 8, 6, 1, 4, 2};
int tree[n];

void add(int k, int x) {
    while (k <= n) {
        tree[k] += x;
        k += k&-k;
    }
}

int sum_f(int k) {
    int s = 0;
    while (k > 0) {
        s += tree[k];
        k -= k&-k;
    }
    return s;
}

int sum_q(int a, int b) {
    return sum_f(b) - sum_f(a-1);
}

void cnstrctBIT() {
    for (int i = 1; i < n; i++) {
        add(i, arr[i]);
    }
}

int main() {
    cnstrctBIT();
    cout << sum_q(3, 7) << endl;
}
