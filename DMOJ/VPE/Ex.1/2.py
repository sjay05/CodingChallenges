from sys import stdin
input = stdin.readline

l1 = map(int, input().split())
l2 = map(int, input().split())


l1.remove(min(l1))
sum1 = sum(l1)

l2.remove(min(l2))
sum2 = sum(l2)

if sum1 > sum2: print sum1
else: print sum2