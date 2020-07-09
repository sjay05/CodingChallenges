#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

/*
Difference Array:
- A data structure that supports range updates
in O(1) and sum queries in O(N).
- Useful when you have multiple range updates
but only have like one query at the end.
*/

// initialized array
vector<int> a = {10, 5, 20, 40};
vector<int> d;

void init() {
    /*
    Initialize the difference array.
    Each index is calculated by the sum of the current
    idx - the one before.

    Ex. 1 2 3 4
    1st index = 2 - 1
    2nd index = 3 - 2
    3rd index = 4 - 3
    Difference Array: [1, 1, 1]
    */
    int n = (int) a.size();
    d.resize(n + 1);

    d[0] = a[0], d[n] = 0;
    for (int i = 1; i < n; i++) {
        int dif = a[i] - a[i - 1];
        d[i] = dif;
    }
}

void update(int l, int r, int k) {
    /*
    Increase arr[l]...arr[r] by k.
    arr[l] and arr[r] (inclusive).
    */
    d[l] += k;
    d[r + 1] -= k;
}

int sum(int l, int r) {
    /*
    We can modify the original array
    to the new values we have in the
    difference array.
    */
    for (int i = 0; i < (int) a.size(); i++) {
        if (i == 0) {
            a[i] = d[i];
        } else {
            a[i] = d[i] + a[i - 1];
        }
    }
    /*
    We can now calculate the sum of the
    values from [l...r];
    */
    int ret = 0;
    for (int i = l; i <= r; i++) {
        ret += a[i];
    }
    return ret;
}

int main() {
    // {10, 5, 20, 40};
    init();
    update(0, 1, 10);
    update(1, 3, 20);
    update(2, 2, 30);
    sum(0, 1);
}
