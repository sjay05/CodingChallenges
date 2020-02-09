from sys import stdin
input = stdin.readline

N = int(input())
l = map(int, input().split())
s = sum(l)
divid = s / N

count = 0
for i in l:
    if i != divid:
        count += 1

print count
