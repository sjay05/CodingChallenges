# Find if a given number is a power of 2:
"""
Normal Approach: O(logN)
- The usual approach would be to repeatedly divide N by 2, if N is even. If we end
up with 0, then it means that N is a power of 2.
"""


def isPowerOfTwo(n):
    if n == 0:
        return False
    if n == 1:
        return True
    else:
        while True:
            if n % 2 != 0:
                return False
            if n % 2 == 0 and n == 2:
                return True
            n = n / 2


print isPowerOfTwo(1048577)