/* --- LONGEST COMMON SUBSEQUENCE --- */
#include <bits/stdc++.h>

using namespace std;

#define str string

/*
Problem Structure:
 Let X be of length m [X(1...M)] and Y of length n [Y(1...n)].
 Build a LCS(x,y) function to return the "longest common sub-seq".
 Ex. X = "ABCBDAB" and Y = "BDCABA", LCS(X,Y) = {"BCBA"}.

Recursive Thought:
 When character's match they are definitely part of the LCS seq.
 However, when they don't, there are 3 possible advancements. Take,
 a as the first (char), and b as the second. Here are the possibilities
 when a != b:
 1) Forget about a
 2) Forget about b
 3) Forget both
 As soon as a == b, include it in the LCS. Once a possibility is done,
 this brings us to another LCS problem. We recurse with this method and
 find one of the possible LCS.

Recursive Pseudo-Code:
 i, j = iterators of the sequences (A, B).

 1) if X[i] == Y[i] : 1 + LCS(i+1, j+1)
 2) if X[i] != Y[i] : LCS(i, j+1)
 3) if X[i] != Y[i] : LCS(i+1, j)
*/

const str X = "ABCBDAB";
const str Y = "BDCABA";

str LCS(str seq, int i, int j)
{
    if (i == X.size() || j == Y.size())
    {
        return seq;
    }
    if (X[i] == Y[j])
    {
        return LCS(seq + X[i], i + 1, j + 1);
    }
    else
    {
        str a = LCS(seq, i + 1, j);
        str b = LCS(seq, i, j + 1);
        return a.size() > b.size() ? a : b;
    }
}

int main()
{
    printf("%s\n", LCS("", 0, 0).c_str());
}
