# Substring Search using Brute Force Approach
# Language = Python 2.7
"""
Ex. Query:
Text: abacbaabcabccabcaabb
Pattern: abcaa
"""

def search(txt, pat):
    a = len(pat)
    b = len(txt)
    i = 0
    while (i <= (b - a) + 1):
        x = 0
        while (x < a):
            if txt[i+x] != pat[x]:
                break
            x += 1
        if (x == a):
            print "Index = %s" %i
        i += 1

if __name__ == "__main__":
    search("abacbaabcabccabcaabb", "abcaa")