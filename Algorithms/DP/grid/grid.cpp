/*
Paths on a Grid:
- Find path from (src to dest) with greatest sum.
Algorithm:
- Recursive function calling on f(x+1, y) and f(x, y+1)
*/
#include <bits/stdc++.h>

using namespace std;

#define MAXN 5
int grid[MAXN][MAXN] = {
    {3, 7, 9, 2, 7},
    {9, 8, 3, 5, 5},
    {1, 7, 9, 8, 5},
    {3, 8, 6, 4, 10},
    {6, 3, 9, 7, 8}
};

int dest[2] = {4, 4};

bool check(int x, int y) {
    if (x <= MAXN-1 and y <= MAXN-1) {
        return true;
    } else {
        return false;
    }
}

int find_path(int x, int y, int count) {
    if (x == dest[0] and y == dest[1]) {
        return count + grid[x][y];
    }
    if (check(x, y) == true) {
        count += grid[x][y];
    }
    if (check(x, y) == false) {
        return 0;
    } 
    else {
        return max(find_path(x+1, y, count), find_path(x, y+1, count));
    }
}

int main() {
   cout << find_path(0, 0, 0) << endl;
}