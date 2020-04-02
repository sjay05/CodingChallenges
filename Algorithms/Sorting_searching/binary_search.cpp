/*===============================================
#	Author:		sjay05
#	File:		binary_search.cpp
#	Desc:		implementation of binary search
===============================================*/
#include <bits/stdc++.h>

using namespace std;

/*
Implementation of binary search:
n = length of arr, x = element we are looking for
l = 0, r = n-1
We find (mid) by doing l + (r-1) / 2
if arr[mid] == x, we return idx
if arr[mid] > x, ignore right half by doing r = m-1;
if arr[mid] < x, ingore left half by doing l = m+1;
if no pos found, return -1
*/

int bin_search(int arr[], int n, int x) {
    // O(log n)
    int l = 0, r = n-1;
    while (l <= r) {
        int mid = l + (r-1) / 2;
        if (arr[mid] == x) 
            return mid;
        if (arr[mid] < x)
            l = mid + 1;
        if (arr[mid] > x)
            r = mid - 1;
    }
    return -1; 
}

/*
This is a different type of binary search. We make
jumps and slow the speed when we get closer to the 
target. The initial jump is n/2, then n/8, then n/16.
Once the element after the jump is larger than target, 
we go back and make smaller jumps, until we find the
element.
*/
int diff_bin_search(int arr[], int n, int x) {
    int idx = 0;
    // ! @param b = jump length
    for (int b = n/2; b >= 1; b /= 2) {
        while (idx+b < n && arr[idx+b] <= x)
            idx += b;
    }
    if (arr[idx] == x)
        return idx;
    else
        return -1;
}

int main() {
    // idx    =  0  1  2  3   4
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int idx = bin_search(arr, n, 10);
    cout << idx << endl;
}