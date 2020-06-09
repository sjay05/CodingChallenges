#include <bits/stdc++.h>

using namespace std;

template<class T, int SZ> struct BIT {
    T bit[SZ+1];
    BIT() {
        memset(bit, 0, sizeof bit);
    }
    void upd(int k, T val) {
        for (; k <= SZ; k += (k&-k)) {
            bit[k] += val;
        }
    }
    T query(int k) {
        int tmp = 0;
        for (; k > 0; k -= (k&-k)) {
            tmp += bit[k];
        }
        return tmp;
    }
    T query(int l, int r) {
        return query(r)-query(l-1);
    }
};


