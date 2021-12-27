#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i=a; i<=b; i++)

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    string s, temp;
    vector<string> vs;
    getline(cin, s);
    istringstream is(s);
    while (is >> temp) vs.push_back(temp);
    for (auto x : vs) {
        reverse(x.begin(), x.end());
        cout << x << ' ';
    }
    return 0;
} 