# LeetCode "Single Number" Solution using BIT MANUPILATION.
array = [4,1,2,1,2]


def single_number(numbers):
    a = 0
    for i in range(len(numbers)-1):
        if i == 0:
            a = numbers[i] ^ numbers[i+1]
        else:
            a = a ^ numbers[i+1]

    return a


print single_number(array)



# PROBLEM:
"""
URL: https://leetcode.com/problems/trapping-rain-water/
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
"""

# ALGORITHM:
'''
First, start by iterating through the list, starting from "1", to "len(list)-1".
To find the number of water blocks in "i"th column:
    - Find the biggest integer in all the numbers to the left of the 
    "i"th index. Implementation -> left_max = max(list[:i])
    - Find the biggest integer in all the numbers to the right of the 
    "i"th index. Implementation -> right_max = max(list[i+1:])
    - Take the smaller number of the two: (left_max and right_max) 
    and assign it to var "main_max".
    - Now, to find the number of water blocks, subtract list[i] from
    "main_max". Implementation -> main_max - list[i]
'''

