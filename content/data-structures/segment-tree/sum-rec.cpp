#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
Segment Tree Implementation For Range Sum Query.
*/

const int maxn = 8;
int arr[] = {5, 8, 6, 3, 2, 7, 2, 6};
int seg[4 * maxn], cnt = 0;

/*
v -> index of vertex
tl, tl -> boundaries of vertex
*/
void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = arr[tl];
    } else {
        int mid = (tl + tr) / 2;
        build(v * 2, tl, mid);
        build(v * 2 + 1, mid + 1, tr);
        seg[v] = seg[v * 2] + seg[v * 2 + 1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        cnt++;
        return seg[v];
    }
    int mid = (tl + tr) / 2;
    int left_v = sum(v * 2, tl, mid, l, min(r, mid));
    int right_v = sum(v * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
    return left_v + right_v;
}

void update(int v, int tl, int tr, int pos, int new_v) {
    if (tl == tr) {
        seg[v] = new_v;
    } else {
        int mid = (tl + tr) / 2;
        if (pos <= mid) {
            update(v * 2, tl, mid, pos, new_v);
        } else {
            update(v * 2 + 1, mid + 1, tr, pos, new_v);
        }
        seg[v] = seg[v * 2] + seg[v * 2 + 1];
    }
}

int main() {
    build(1, 0, maxn - 1);
    cout << sum(1, 0, maxn - 1, 1, 3) << "\n";
    update(1, 0, maxn - 1, 1, 10);
    cout << sum(1, 0, maxn - 1, 1, 3) << "\n";
}
