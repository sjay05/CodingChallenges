/* --- Hamming Distance Problem --- */
#include <bits/stdc++.h>

using namespace std;

/*
 * The Hamming Distance - hamming(a, b) between 2 str (a and b) is
 * the number of positions where the strings differ.
 *
 * Ex. hamming(01101, 11001) = 2
 *
 * A straightforward way of approaching this problem would be to
 * go through all the indexes and check if the char is different.
 * This yields a Big-O of O(N^2).
 *
 * However this can be done with bitwise operators and g++ functions.
 *
 * Convert the two string's to int's and then do xor (a^b)
 * Then use __builtin_popcount(a^b) to count the number of ones.
 * Remember, xor puts 1 if both numbers are diff - (0, 1) or (1, 0);
 * This approach yields a Big-O of O(1).
 */

int BinToDec(string s)
{
    int n = 0;
    int iter = s.size() - 1;
    for (char i : s)
    {
        if (i == '1')
        {
            n += ((1 << iter));
        }
        iter--;
    }
    return n;
}

int hamming(string x, string y)
{
    int a = BinToDec(x);
    int b = BinToDec(y);
    return __builtin_popcount(a ^ b);
}

int main()
{
    printf("%d\n", hamming("01101",
                           "11001"));
}
