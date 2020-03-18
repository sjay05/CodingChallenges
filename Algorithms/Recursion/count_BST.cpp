/* --- COUNT UNIQUE BINARY SEARCH TREES --- */
#include <bits/stdc++.h>

using namespace std;

/*
Problem Structure:
 Given n, how many structurally unique BST's (binary search trees) that
 store values [1...n]?

Background Knowledge:
 Binary Search Tree (BST) is a tree. The left subtree consists of elements
 less than root element and the right subtree contains elements greater
 than root element.

Recursive Structure:
 It is known that the number of BSTs is a Catalan Number and denoted by C_n.
 Assume that the nodes of the tree are number from 1 to n. We select a node
 as the root and all nodes less than root node goes to the left subtree and
 elements greater than root node go into right subtree.

 Assume that root node is the i'th element in [1...N]. This means, we get (i-1)
 elements on the left subtree and (n-i) elements on the right subtree. Since
 C_n is the catalan number for n elements, C_(i-1) represents the catalan number
 for the left subtree and C_(n-i) represents the right subtree. Catalan num, for
 const i is C_(i-1) * C_(n-i).

Improvements:
 Using memoization, we can reduce the time complexity from O(N^4) to O(N^2).
 Both implementation's follow:

O(1) Sol:
 The Catalan number can also be found with a direct equation.
 C_n = (2n)! / (n+1)!n!
 */

#define MAXN 2000

int countBST(int n)
{
    if (n == 0)
        return 1;
    int count = 0;
    for (int i = 1; i <= n; i++)
        count += countBST(i - 1) * countBST(n - i);
    return count;
}

int table[MAXN];
int countBST_2(int n)
{
    if (n == 0)
        return 1;
    if (table[n] != 0)
        return table[n];
    int count = 0;
    for (int i = 1; i <= n; i++)
        count += countBST_2(i - 1) * countBST_2(n - i);
    table[n] = count;
    return count;
}

int main()
{
    printf("%i\n", countBST_2(3));
}