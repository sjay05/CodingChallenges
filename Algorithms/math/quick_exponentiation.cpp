//  quickExponent.cpp
//  dsalgoC++

//  Created by Alpha on 2019-12-14.
//  Copyright © 2019 Alpha. All rights reserved.

// Recursive Way of Calculating N^a.
// For ex:
    // 8^10 = [8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8 * 8]
    // Then, split it in half and only do the operations for half
    // num = [8 * 8 * 8 * 8 * 8] * num
    // Continue Recursively...

#include <stdio.h>
#include <iostream>

using namespace std;

// Globals
int a;

int quick_exponent(int n) {
    if (n == 1) return a; // if exp is 1, return value
    if (n == 0) return 1; // if n^0, then return 1
    int result = quick_exponent(n/2);
    if (n % 2 == 0) return result * result;
    else return result * result * a;
}

int main() {
    int N;
    cout << "Number?: ";
    cin >> N;
    cout << "Exponent?: ";
    cin >> a;
    cout << quick_exponent(N) << endl;

}
