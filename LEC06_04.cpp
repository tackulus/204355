#include <bits/stdc++.h>
using namespace std;

#define long long long
#define REP(i,a,b) for (int i=a; i<=b; i++)

string get_string() { return {}; }

string shift(string s) {
    for (long i = s.length() - 1; i > 0; i--) if (s[i-1] < s[i]) {
        string tail = s.substr(i), ans = s.substr(0, i-1);
        multiset<char> pool;
        for (auto x:tail) pool.insert(x);
        auto it = pool.lower_bound(char (s[i-1]+1));
        ans += *it;
        pool.erase(pool.find(*it));
        pool.insert(s[i-1]);
        for (auto x:pool) ans += x;
        return ans;
    }

    return "No Successor";
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    string s;
    cin >> s;
    cout << shift(s);
    return 0;
} 
