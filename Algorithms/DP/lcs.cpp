/* --- LONGEST COMMON SUBSEQUENCE --- */
#include <bits/stdc++.h>

using namespace std;

/*
Problem Structure:
 Let X be of length m [X(1...M)] and Y of length n [Y(1...n)].
 Build a LCS(x,y) function to return the "longest common sub-seq".
 Ex. X = "ABCBDAB" and Y = "BDCABA", LCS(X,Y) = {"BCBA"}.

Dynamic Programming Thought:
 Start by generating a matrix[M+1][N+1]:
       0 1 2 3 4 5 6 7
         A B C B D A B
      ________________
 0   | 0 0 0 0 0 0 0 0
 1 B | 0 0 0 0 0 0 0 0
 2 D | 0 0 0 0 0 0 0 0
 3 C | 0 0 0 0 0 0 0 0
 4 A | 0 0 0 0 0 0 0 0
 5 B | 0 0 0 0 0 0 0 0
 6 A | 0 0 0 0 0 0 0 0

 Here is our structure:
 1) if X[i] == Y[i], then dp[i][j] = 1 + dp[i-1][j-1] <-- (the word until then).
    Ex. for example, when we check c == c (dp[3][3]), we add 1 to Lcs of ("AB")
    and ("BD").
 2) If X[i] != Y[i], then we check whether it suffices to ignore i or j, by checking
    dp[i-1][j] and dp[i][j-1].
    Ex. for example, when we check c != a (dp[3][4]), we check if lcs("BDCA", "AB") or
    lcs("BDC", "ABC") is bigger.

 After completing our DP, the table will look like so:
        0 1 2 3 4 5 6 7
          A B C B D A B
      ________________
 0   |  0 0 0 0 0 0 0 0
 1 B |  0 0 0 0 1 1 1 1
 2 D |  0 0 1 1 1 1 1 1
 3 C |  0 0 1 1 1 2 2 2
 4 A |  0 1 1 2 2 2 3 3
 5 B |  0 1 1 2 2 3 3 3
 6 A |  0 1 1 2 2 3 3 4

 Therefore, LCS is dp[M][N] which is 4.
 This algorithm's time complexity is O(nm).
*/

string X = "ABCBDAB";
string Y = "BDCABA";
int N = X.size();
int M = Y.size();

int lcs()
{
    int dp[M + 1][N + 1];
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (X[j] == Y[i])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[M][N];
}

int main()
{
    vector<int> v = {1, 2, 3, 4};
    for (int i : v)
    {
        printf("%i\n", i);
    }
}