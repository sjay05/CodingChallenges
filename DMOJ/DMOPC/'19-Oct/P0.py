line1 = raw_input().split()
N = int(line1[0])
H_min = int(line1[1])
H_max = int(line1[2])

heights = raw_input().split()
heights = [int(i) for i in heights]

count = 0
for i in heights:
    if H_min <= i <= H_max:
        count += 1

print count