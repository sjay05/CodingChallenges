/* --- AND (&) OPERATOR --- */
#include <bits/stdc++.h>

using namespace std;

/*
x & y produces a number with one Bitmask in positions
 where both x and y have one Bitmask.

 (1 and 1) = 1
 (else) = 0

So 22 & 26 = 18, because
    10110 (22)
  & 11010 (26)
  ____________
  = 10010 (18)

*/

/*
 We can find if a number is even or odd.

 Even numbers (bin) end in 0.
 Odd numbers (bin) end in 1.

 bin(1) = 1;

 We only care about the last bit. Since (bin) is 1. Since odd numbers
 end in 1, when (&)'ned with bin(1), they will form a 1 again - which
 means they are odd. However if it is a even number, it will be a 0,
 and forms a 0 when (&)'ned with bin(1).

 Ultimately,
    if (n & 1) == 0 then even
    if (n & 1) == 1 then odd
 */

/*
We can also find if a number is a multiple of 2^k;

 x is divisible by 2^k when x & (2^k - 1) = 0;

 */

void oddOrEven(int x) {
    if ((x & 1) == 0) {
        printf("Even\n");
    } else {
        printf("Odd\n");
    }
}

void divBy2k(int n, int m) {
    // 1 << m == 2^m
    if ((n & ((1 << m) - 1)) == 0) {
        printf("Divisible\n");
    } else {
        printf("Not divisible.\n");
    }
}

int main() {
    oddOrEven(5); // Find if 5 is odd.
    divBy2k(16, 3); // Find if 16 is a multiple of 2^3.
}