#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

/*
Subset Sum:

You are given N numbers. Check if there is a subset 
of them, with the sum equal to target value S. (N <= 20).
*/

/*
Mask the set of N with a choice of diferent numbers.

x = [0000000000] (n zeros)

When a position (i) in x is (1), it means we have choosen
that number.

For example our array of n numbers = [1,2,3,4,5];

Our x value = 00001 = means we only choose (5) in our
set.

Once generated a x value we can iterate over it with 
integer (i) and then check if the i'th bit is set to 0 or 1.

If set to 1 we can add it to the sum otherwise we 
continue on. If the sum of the particular subset 
equals our target S we can print it.

Time Complexity: O(2^n*n)

Bitwise Operations:

    for (int msk = 0; msk < (1 << n); msk++) 

    ^^ We are iterating over the 2^n combinations
    of sets with (1 << n).

    To check if the i'th bit is 1 or 0. We can 
    create a bit number of 2^(i-1) and use the (&) 
    operator to check.

    Example check if the 5'th bit in 11101 is 1.

    Since we wan't to check the 5'th bit, calculating
    2^(5-1) gets us 0b10000 = 10000.

    We use the AND operator now. This operator looks
    for two positions with (1).

      10000
    & 11101
    =========
      10000

    We have found that the 5'th bit is a (1). Remember
    when saying (0th position in a bit) it signifies the 
    rightmost position.   
*/

int main() {
    ll n = 5, s = 12;
    vector<int> a = {1, 2, 3, 4, 5};
    /*Generate all 2^n binary subsets*/
    for (int msk = 0; msk < (1 << n); msk++) {
        ll sum = 0; vector<int> arr;
        for (int i = 0; i < n; i++) {
            if (msk & (1 << i) != 0){
                arr.push_back(a[i]);
                sum += a[i];
            }
        }
        if (sum == s) {
            printf("YES ");
            for (int i : arr) 
                printf("%i ",i);
            printf("\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}