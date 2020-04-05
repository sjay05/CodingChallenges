/*===================================
#	Author:		sjay05
#	File:		time.cpp
#	Desc:		calculate execution time
===================================*/
#include <bits/stdc++.h>
#include <time.h>

#define start_time() clock_t tStart = clock()
#define get_time (double)(clock() - tStart)/CLOCKS_PER_SEC
#define print_time() printf("Time Taken: %.6fs\n", get_time)

using namespace std;

int main() {
    start_time();
    int c = 0;
    for (int i = 0; i < 100; i++) {
        c++;
    }
    print_time();
    return 0;
}