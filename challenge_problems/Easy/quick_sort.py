# Quick-sort algorithm using a PIVOT.
"""
Example: [3, 5, 2, 1, 4]
Pivot (first element in array) = 3
TAKE TWO LISTS:
    1) less[] containing all the elements less than the pivot
    2) greater[] containing all the elements greater than the pivot

BASE CONDITION:
If the list is ever empty, or only has 1 element: return the list

RECURSION:
return quicksort(less) + [pivot] + quicksort(greater)
"""


def quicksort(array):
    if len(array) < 2:  # Base condition
        return array
    else:
        pivot = array[0]  # Pivot = first element
        less = [i for i in array[1:] if i <= pivot]  # array containing elements less than pivot
        greater = [i for i in array[1:] if i > pivot]  # array containing elements greater than pivot

        return quicksort(less) + [pivot] + quicksort(greater) # recursive function call
                                                    

print quicksort([10, 5, 2, 3, 9])
