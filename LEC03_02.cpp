#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (long long i=a; i<=b; i++)

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long long n, x, memo = 0, ans = 0;

    cin >> n;
    REP(i, 1, n) {
        cin >> x;
        memo = max(x, memo + x);
        ans = max(ans, memo);
    }

    cout << ans << "\n";
    return 0;
} 