#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (long long i=a; i<=b; i++)

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long long n, m, x, total=0;

    cin >> n >> m;
    REP(j,1,m) {
        cin >> x;
        long long l=0, memo=0, ans=0, al=0, ar=0;
        memo = max(x, memo + x);
        ans = max(ans, memo);
        REP(i, 1, n-1) {
            cin >> x;
            if (x > memo+x) {
                l=i;
            }
            memo = max(x, memo + x);
            
            if (ans < memo) {
                al=l; ar=i;
            }
            ans = max(ans, memo);
        }
        cout << al << " " << ar << "\n";
        cout << ans << "\n";
        total += ans;
    }
    cout << total << "\n";
    return 0;
} 