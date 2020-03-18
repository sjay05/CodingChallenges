#include <bits/stdc++.h>

using namespace std;
constexpr const char nl = '\n', sp = ' ';

typedef pair<int,int> pii;
typedef vector<int> vi;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define print(x) cout<<x<<nl
#define str(x) to_string(x)
// conversion to int = stoi(x)
#define mp make_pair
#define pb push_back

#define matrix(type, name, width, length) \
    vector<vector<type>> name(length, vector<type>(width))

template <typename T> pair<bool, int > find
(const vector<T>  & vec, const T  & element) {
    pair<bool, int > result;
    auto it = find(vec.begin(), vec.end(), element);
    if (it != vec.end()) {
        result.second = distance(vec.begin(), it);
        result.first = true;
    }
    else {
        result.first = false;
        result.second = -1;
    }
    return result;
}

#define obsv(x) cerr<<(#x)<<" = "<<(x)<<nl
template <typename T> void printArr(const vector<T> &vec) {
    string x = "[";
    for (int i = 0; i < vec.size(); i++) {
        if (i == vec.size()-1) x += to_string(vec[i]);
        else x += to_string(vec[i]) + "," + " ";
    }
    x += "]"; cout<<x<<endl;
}
template <typename T> void print2dArr(const vector<vector<T>> &vec) {
    for (auto line : vec) {
        printArr(line);
    }
}

/* Experimental Template From now...*/

template <typename T> bool keyExist(T key, const map<T,T> &m) {
    return m.find(key) != m.end();
}
