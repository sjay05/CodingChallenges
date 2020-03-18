/* --- BRIDGE-CROSSING DP --- */
#include <bits/stdc++.h>

using namespace std;

/*
Problem Statement:
 Consider a long river going from left to right. There
 are n cities on top and bottom of the river. The cities
 are numbered from [1..n] but the order is not known. We 
 wan't to connect as many bridges as we can from the south 
 to north, such that no 2 bridges intersect. We can only 
 connect city [i] to city [i]. (City 1 -> 4 is not a valid 
 bridge). 

Problem Thought:
 When we trace this problem out and construct bridges 
 we notice that the cities on the north which are 
 connected form a longest increasing subsequence based
 on their index. 

Recursive Structure:
 Let us say that F(i) is the index of the northern city
 [i]. We need the array [F(1)....F(N)]. Now to find the 
 total number of bridges, we find the LIS of [f(1)..f(n)].
*/

#define all(x) x.begin(), x.end()
#define index(x, e) distance(x.begin(), find(all(x), e))

vector<int> north = {1, 5, 3, 2, 6};
vector<int> south = {6, 2, 5, 3, 1};

int bridge_cross() {
    vector<int> arr;
    for (int i : south) {
        int x = index(north, i);
        arr.push_back(x+1);
    }
    int n = arr.size();
    vector<int> dp(n);
    dp.assign(n, 1);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < i; j++) 
            if (arr[j] < arr[i]) 
                dp[i] = max(dp[i], dp[j]+1);
            
    int ret = 0;
    for (int i : dp)
        ret = max(ret, i);
    
    return ret;

}

int main() {
    printf("%i\n", bridge_cross());
}