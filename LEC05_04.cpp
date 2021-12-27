#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i=a; i<=b; i++)

int ordinal(char x) { return (int) x - (int) '@';}

int ABC(string s) {
    int n;
    vector<int> pile;
    bool state;
    if (s.length() != 0) pile.push_back(27);
    for (auto x:s) {
        state = true;
        n = ordinal(x);
        REP(i, 0, pile.size()-1) {
            if (pile[i] >= n) {
                pile[i] = n;
                state = false;
                break;
            }
        }
        if (state) pile.push_back(n);
    }
    return pile.size();
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    string s;
    cin >> s;
    cout << ABC(s) << '\n';
    return 0;
} 