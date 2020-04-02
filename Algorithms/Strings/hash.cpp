/* STRING HASHING */
#include <bits/stdc++.h>

using namespace std;

/*
The following code generates a hash given
a string s of length using the polynomial
rolling hashing function with p and m as 
some chosen, positive numbers. p and m must 
be primes. If m is a large number, the 
probability of two random string generated 
hashes coliding is about 1/m. Also, keep p
a prime number equal to the number of distinct
char's that might appear.

hash(s) = s[0] + (s[1] * p) + (s[2] * p^2)
					+...(s[n - 1] * p^{n-1}) mod m
*/

using ll = long long;

long long compute_hash(string s) {
    const int p = 31, m = 1e9 + 9;
    ll hash_value = 0;
    ll p_pow = 1;

    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

int main() {
	string s; cin >> s;
	cout << "Hash = " << compute_hash(s) << endl;
}

