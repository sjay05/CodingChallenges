/*===================================
#	Author:		sjay05
#	File:		time.cpp
#	Desc:		calculate execution time
===================================*/
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int main() {
    clock_t tStart = clock();
    /* ...code... */
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}