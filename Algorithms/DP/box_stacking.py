# --- BOX-STACKING DP ---
import sys

"""
Problem Statement:
 Given [n] rectangular 3-D boxes, the dimensions of the i'th
 box is h_i, w_i, and d_i. We want to create a stack of boxes
 as tall as possible, but a box can only be stacked on top of
 another one if the dimensions of the lower box is stricly
 larger than the ones of the higher one. Boxes can be rotated
 to use any side as it's base.

Breaking it down:
 Every box can be rotated to use other side's as it's base.
 Let, box_i have dimensions (h, w, d). The 3 possible bases are
 (h, w, d) (d, h, w) and (w, h, d). All permutations are maintained
 in an array.

Recursive Structure:
 We can use the LIS dynamic programming structure to approach
 this problem.
 
 Start by sorting the boxes by base area. Let us say F(j) is the
 tallest stack with box j on top. This means we have to find the largest
 substack with box i such that box j is strictly smaller than i. 

 So,...
 F(j) = MAX (i < j and w_i > w_j and d_i > d_j) {F(i)} + h_i

 Time Complexity : O(N^2)
 """

class Box:
    def __init__(self, h, w, d):
        self.h = h
        self.d = d
        self.w = w
    
    # for sorting purposes
    def __lt__(self, other):
        return self.d * self.w < other.d * other.w 

def box_stack(boxes, n):
    # @param n = len(boxes)
    perms = []

    for box in boxes:
        h, w, d = box.h, box.w, box.d 
        perms.append(Box(h, w, d))
        # 2nd type
        perms.append(Box(d, h, w))
        # 3rd type
        perms.append(Box(w, h, d))

    n = n * 3
    perms.sort(reverse = True)
    
    # int dp[n]
    dp = [0 for i in range(n)]
    # every box has it's own height
    for i in range(n): 
        dp[i] = perms[i].h    


    for i in range(1, n):
        for j in range(0, i):
            if (perms[i].w < perms[j].w and perms[i].d < perms[j].d):
                if dp[i] < dp[j] + perms[i].h: 
                    dp[i] = dp[j] + perms[i].h
    
    maxn = -1
    for i in range(n): 
        maxn = max(maxn, dp[i])

    return maxn

if __name__ == "__main__":
    print(box_stack([Box(4, 6, 7), Box(1, 2, 3), 
           Box(4, 5, 6), Box(10, 12, 32)], 4))
