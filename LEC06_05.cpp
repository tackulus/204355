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
    set<string> pool;
    map<string, int> field;
    int n;
    string x;
    cin >> n;
    REP(i,1,n) {
        REP(j,1,5) {
            cin >> x;
            pool.insert(x);
        }
        string tag=get_string();
        for (auto x:pool) tag += x;
        field[tag] += 1;
        pool.clear();
    }
    int MAX = 0, count = 0;
    for (auto p:field) MAX = max(MAX, p.second);
    for (auto p:field) if (p.second == MAX) count += MAX;
    cout << count;
    return 0;
} 
