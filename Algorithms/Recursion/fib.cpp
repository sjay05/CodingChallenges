/* --- Fib Recursion --- */
#include <bits/stdc++.h>

using namespace std;

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

// @memoize
int mem[100];
int fib2(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    if (mem[n] != 0)
    {
        return mem[n];
    }
    return mem[n] = fib2(n - 1) + fib(n - 2);
}

int main()
{
    printf("%d\n", fib2(6));
}