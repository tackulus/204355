#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i=a; i<=b; i++)

int lego(vector<int> v) {
    int n = v.size(), s = 0, ans = 0;
    for (auto x : v) s += x;
    s /= n;
    for (auto x : v) ans += max(0, s - x);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n, x;
    vector<int> v;
    cin >> n;
    REP(i, 1, n) {
        cin >> x;
        v.push_back(x);
    }

    cout << lego(v) << '\n';
    return 0;
} 