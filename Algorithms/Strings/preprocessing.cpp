/* PREPROCESSING HASH VALUES FOR STRINGS */
#include <bits/stdc++.h>

using namespace std;

/*
Using hashing, we can compute the hash value of
any substr string s in O(1) after O(n) preprocessing.
We construct an "prefix hash" array h such that h[k]
holds the hash value of s[0...k]. Just like the hash
function, we have string s, and two numbers (p and m).

We use the following recurrence to compute the values 
of h[k]:

h[0] = s[0]
h[k] = (h[k-1]*A )
*/

int main() {
    // ! unfinished (in gitignore)
    // TODO: Finish code and remove from gitignore
}
