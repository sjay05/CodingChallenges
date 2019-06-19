# Question: I have 12 identical pieces of candy. In how many different ways can I distribute
# the candies to 4 different kids? (All of the candies must be given out.)
# Credits: AoPS "Introduction to Counting & Probability" - by David Patrick
"""
Below is a recursive solution to generate all the combinations of splitting the
12 pieces of candy to all 4 children.

NOTE: A child can receive as low as 0 candies.
"""

valid_strings = []


def distribute_candy(n, comb, kids):
    if kids == 1:
        comb += str(n)
        valid_strings.append(comb)
        return

    minimum = n
    for i in range(0, minimum+1):
        comb += str(i)
        distribute_candy(n-i, comb, kids-1)
        comb = comb[:-1]


distribute_candy(12, '', 4)
print valid_strings
print len(valid_strings)
