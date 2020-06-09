/*==============================================
# Name        : ord_set.cpp
# Author      : sjay05
# Language    : C++ (GCC-8)
# Description : Policy Based Data Structure
===============================================*/
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update> ord_set;

/*
All operations are done in O(log n) time.
*/

int main() {
    ord_set s;
    /* Set = {1, 5, 6, 17, 88}*/
    s.insert(17), s.insert(6);
    s.insert(88), s.insert(1);
    s.insert(5);

    /**
     * find_by_order(x)
     * - returns a iterator to the kth
     * element (0-indexed) in O(log n) time.
    */
    cout << *s.find_by_order(2) << "\n";

     /**
     * find_by_order(k)
     * - Returns number of items strictly
     * smaller than item k in the set
    */
    cout << s.order_of_key(6) << "\n";

}
