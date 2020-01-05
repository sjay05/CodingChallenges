/*
Substring Search using Brute Force Approach
Language = C++11
Time Complexity = O(nm)

Ex. Query:
Text: abacbaabcabccabcaabb
Pattern: abcaa
*/
#include <bits/stdc++.h>

using namespace std;

void search(string txt, string pat) {
    int a = pat.length();
    int b = txt.length();
    for (int i = 0; i <= (b - a) + 1; i++) {
        int x = 0;
        while (x < a) {
            if (txt[i+x] != pat[x]) {
                break;
            }
            x++;
        }
        if (x == a) {
            printf("Index = %d\n", i);
        }
    }
}

int main() {
    search("abcaaabcabccabcaabb", "abcaa");
}