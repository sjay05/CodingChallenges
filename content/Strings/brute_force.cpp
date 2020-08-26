/* BRUTE FORCE SEARCH */
#include <bits/stdc++.h>

using namespace std;

/*
This is the brute force algorithm to search 
for the presence of a pattern string p in text
t by checking each position. 

Note: |p| = len(p)

Time Complexity: O(|p|*|t|)
*/

int find_match(string p, string t) {
	/*
	Returns index of string p in t, otherwise -1.
	*/
	int plen, tlen;
	plen = (int) p.size();
	tlen = (int) t.size();

	for (int i = 0; i < (tlen - plen); ++i) {
		int j = 0;
		while (j < plen && t[i + j] == p[j]) {
			j++;
		}
		if (j == plen) return i;
	}
	return -1;
}

int main() {
	cout << find_match("ABBA", "ABBCBCABBACD") << endl;
}
