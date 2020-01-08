import sys

def fact(x):
    if x == 1:
        return 1
    else:
        return x * fact(x-1)
    
def fact_tabulate(x):
    dp = [0] * x
    for i in range(x):
        if i == 0:
            dp[i] = 1
        else:
            dp[i] = (i+1) * dp[i-1]
            
    return dp[x-1]
            
if __name__ == "__main__":
    print fact_tabulate(5)