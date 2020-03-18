/* --- Prefix Sum Array Implementation --- */
#include <bits/stdc++.h>

using namespace std;

/* ----------------------------------------------------
 *   Prefix Sum Array:
 *   - Build: O(n)
 *   - Range Query: O(1)
 *   - Brute Force Method: O(nq)
 *
 *   Ex.
 *          0  1  2  3  4  5  6  7
 *   arr = [1, 3, 4, 8, 6, 1, 4, 2]
 *
 *          0  1  2  3   4   5   6   7
 *   psa = [1, 4, 8, 16, 22, 23, 27, 29]
 *
 *   Range Query = query[i, j]  = psa[j] - psa[i-1]
 * ----------------------------------------------------
 */

vector<int> build(vector<int> &arr)
{
    vector<int> psa;
    int sum = 0;
    for (int i : arr)
    {
        sum += i;
        psa.push_back(sum);
    }
    return psa;
}

int query(int i, int j, vector<int> &psa)
{
    if (i == 0)
        return psa[j];
    else
        return psa[j] - psa[i - 1];
}

int main()
{
    vector<int> arr = {1, 3, 4, 8, 6, 1, 4, 2};
    vector<int> psa = build(arr);
    printf("%d", query(3, 6, psa));
}