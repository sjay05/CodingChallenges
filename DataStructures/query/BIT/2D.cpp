/*===================================
#	Author:		sjay05
#	File:		2D.cpp
#	Desc:		2D BIT
===================================*/
#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

int sz;
int BIT[MAXN][MAXN];

/*
Add (val) to (x, y). 
*/
void update(int x, int y, int val) {
    for (int i = x; i <= sz; i += i&-i) {
        for (int j = y; j <= sz; j += j&-j) {
            BIT[i][j] += val;
        }
    }
}

/*
Sum of box grid from (0, 0) to (x, y).
*/
int sum(int x, int y) {
    int ret = 0;
    for (int i = x; i > 0; i -= i&-i) {
        for (int j = y; j > 0; j -= j&-j) {
            ret += BIT[i][j];
        }
    }
    return ret;
}

int main() {

}