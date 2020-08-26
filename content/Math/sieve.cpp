/* --- Sieve of Eratosthenes Implementation --- */
#include <bits/stdc++.h>

using namespace std;

/* ---------------------------------------------------------------
 * The sieve of Eratosthenes is a algorithm that finds
 * all prime numbers from [1;N] using O(n log log n) operations.
 * Mark all multiples of numbers from 2 to N, NOT PRIME, and the
 * numbers leftover are PRIME NUMBERS.
 * ---------------------------------------------------------------
 */

int main()
{
    const int n = 100; /* Finding primes < N */
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        // (i * i <= n) is an optimization.
        if (is_prime[i] && i * i <= n)
        {
            // int j = i*i is an optimization.
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    int count = 0;
    // Finding # of primes and which numbers are primes
    for (int i = 0; i < is_prime.size(); i++)
    {
        if (is_prime[i])
        {
            count++;
            printf("%d -> %s", i, "Prime\n");
        }
        else
        {
            printf("%d -> %s", i, "Not Prime\n");
        }
    }
    printf("%d PRIME numbers from [1...%d]\n", count, n);
}
