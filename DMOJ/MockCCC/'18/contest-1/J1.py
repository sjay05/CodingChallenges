# MOCK CCC '18 CONTEST 1 J1 - A String Problem

# Solution 1: Keep iterating N until a number without 0 is found:
N = input()
i = 1
while True:
    if "0" in str(N+i):
        i += 1
    else:
        print N+i
        break

# Solution 2: Add 1 to N, and replace all 0s with 1.
import sys
N = int(sys.stdin.readline())
N = str(N+1)
ans = ""
for i in N:
    if i != "0":
        ans += i
    else:
        ans += "1"

print int(ans)