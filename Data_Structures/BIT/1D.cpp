/* --- 1D BINARY INDEXED TREE --- */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 8; // # of elements
//           0  1  2  3  4  5  6  7
int arr[] = {1, 0, 2, 1, 1, 3, 0, 4};
vector<int> BIT(MAX);

void update(int k, int v) {
    /*
    k = indx which need's to be updated
    v = value to be updated
    */
    for (int i = k; i <= MAX; i += i&-i) {
        BIT[i] += v;
    }
}

int sum(int n) {
    /*
    Query sum for [1] to [n];
    */
    int su = 0;
    for (int i = n; i > 0; i -= i&-i) {
        su += BIT[i];
    }
    return su;
}

int main() {
    for (int i = 1; i < MAX; i++) {
        update(i, arr[i]);
    }

    // Ex. Query for Sum from [3] to [5]
    int i = 0; int j = 5;
    printf("%i\n", sum(j) - sum(i - 1));
}