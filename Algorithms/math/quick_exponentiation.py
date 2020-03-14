# Recursive Way of Calculating N^a.
# For ex:
# 8^10 = [8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8]
# Then, split it in half and only do the operations for half
# num = [8 * 8 * 8 * 8 * 8] * num
# Continue Recursively...


def quick_exponent(n, a):
    if n == 1:
        return a
    if n == 0:
        return 1

    else:

        result = quick_exponent(n / 2, a)
        if n % 2 == 0:
            return result * result
        else:
            return result * result * a


answer = quick_exponent(3, 2)
print answer
