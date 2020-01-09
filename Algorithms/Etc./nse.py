"""
Nearest Smallest Elements: https://cses.fi/book/book.pdf
- Find the first element on the left side of a index (precede) 
  that is smaller for all indexes.
Ex.      [1, 6, 4, 10, 2, 5]
Output: 
INF
1
1
4
1
2

Algorithm: Amortized Analysis (Stack Approach)
- Append to stack as long as arr[i] > stack.pop() and stack.pop() is the nearest element for arr[i]
- If arr[i] < stack.pop(), keep pop() until stack == empty or stack.pop() < arr[i]
"""

def nse(arr):
    stack = list()
    for i in range(len(arr)):
        while (len(stack) > 0 and stack[-1] >= arr[i]): # S[-1] = last element
            stack.pop()
        if len(stack) == 0:
            print "INF"    
        else:
            print stack[-1]
        
        stack.append(arr[i])
    
nse([1, 6, 4, 10, 2, 5])
                
    