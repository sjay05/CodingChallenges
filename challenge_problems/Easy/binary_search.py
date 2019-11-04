# Binary Search through list
"""
Running Time: O(log n)
BINARY SEARCH:
100 elements -> 7 guesses
4 billion elements -> 32 guesses
"""


def binary_search(list, item):
    low = 0
    high = len(list) - 1

    while low <= high:
        mid = (low + high)/2
        guess = list[mid]
        if guess == item:
            return True
        if guess > item:
            high = mid - 1
        if guess < item:
            low = mid + 1
    return False


my_list = sorted([1, 2, 5, 3, 7, 9, 0, 3])
print binary_search(my_list, 5)
