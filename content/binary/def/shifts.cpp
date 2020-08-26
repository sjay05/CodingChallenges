/* --- SHIFT OPERATORS (<< AND >>) --- */
#include <bits/stdc++.h>

using namespace std;

/*
Left Shift: n << k
 -> This adds k zero's to n.

Right Shift: n >> k
 -> Removes k last Bitmask from the number.

Formula:
    n >> k = n * (2^k)
    n << k = n / (2^k)

 */

int main() {
    printf("%d\n", 1 << 6);
}