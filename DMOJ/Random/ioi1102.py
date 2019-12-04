import sys

nk = sys.stdin.readline().split()
n = int(nk[0])
k = int(nk[1])
psa = []
for i in range(n):
    a = int(sys.stdin.readline())
    if i == 0:
        psa.append(a)
    else:
        psa.append(a+psa[i-1])


def hottest(k):
    highest_sum_so_far = 0

    for i in range(k, len(psa)+1):
        if i > k:
            sum = psa[i-1] - psa[i-k-1]
        else:
            sum = psa[i-1]

        if sum > highest_sum_so_far:
            highest_sum_so_far = sum

    return highest_sum_so_far

print hottest(k)