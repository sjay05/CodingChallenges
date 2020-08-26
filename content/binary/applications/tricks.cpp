#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define pass (void)0

/*
Binary Operator Tricks
*/

int main() {
    /*
    XOR - ONLY ONE BIT IS 1.
    We can use this to check if two numbers are equal or not.
    */
    int a = 4, b = 5;
    if (a ^ b) { // another way to say (a != b)
        pass;
    }

    /*
    Set i'th bit in a number:
        Meaning 1 -> 0 or 0 -> 1:

    For example:
        3 = 0011 (let's set the 2nd bit 0011)
                                         ^
        When doing this we get 0111 which is 7.

    To get 7 we can do number |= (1 << bit_pos).
    
    Basically 1 << bit_pos is a number with one (1) 
    followed by bit_pos (0's). So in this case since
    bit_pos is 2, we will get 0100. Now we wan't to retain
    the one's from the previous number. Since the OR only
    looks for at (least) one 1 we can use this with (1 << bit_pos).

    In process (3 | (1 << 2)) =
      0011
    | 0100
    --------
      0111

    Hence we set the 2'nd bit from 0 to 1.
    */
    int n = 3;   // 0011
    int pos = 2; // 0 -> 1
    n |= (1 << pos)

    /*
    Term: Least Significant Bit (LSB):

    The binary position giving the units value, (the 0'th bit),
    determining a numbers polarity.

    For example: 0001 (1 is the LSB).
    
    To find a numbers LSB, we can use the & (AND) operator.
    Since the AND operator looks for positions with 2 one's,
    we can AND the number with the number 1 (0001). This way,
    if the LSB of the number is 1, 1 & 1 will be 1, or else 0.

    We can check polarity (even | odd) with LSB.

    LSB (0) = even
    LSB (1) = odd
    */
    int num = 11;
    if (num & 1) {
        // LSB = 0
        pass;
    }
    else {
        // LSB = 1
        pass;
    }

    /*
    Counting number of SET bits.

    Given an integer (n) in binary form, we wan't to
    calculate the number of (set) bits (number of 1s).

    Ex. 6 = 0110 and number of SET bits are (2 (2 ones)).

    2 Ways to Do this:

    1) use c++'s __builtin_popcount() 
    2) Brian Kernighan’s Algorithm (https://www.geeksforgeeks.org/count-set-bits-in-an-integer/)
    */
    int x = 35; // 100011
    int num_of_bits = __builtin_popcount(x);

    // Brian Kernighan's Algorithm O(log n)
    int number_of_bits = 0;
    while (x) {
        x &= (x - 1);
        number_of_bits++;
    }
    /*
    Check if the i'th bit is Set (1 | 0):
    Given (n) and (pos) to check if i'th 
    bit is 1 do n & ( 1 << pos ).
    */   
    int num = 5, pos = 1;
    if (num & (1 << pos)) {
        
    }
}
