/* --- OR (|) OPERATOR --- */
#include <bits/stdc++.h>

using namespace std;

/*
x | y produces a number that has one Bitmask in positions
 where at least one of x and y have one Bitmask.

 (1 - 0) = 1
 (0 - 1) = 1
 (1 - 1) = 1
 (0 = 0) = 0

Ex. 22 | 26 = 30

    10110 (22)
(|) 11010 (26)
   ____________
    11110 (30)
 */

int main() {
    printf("%d\n", 22|26);
}