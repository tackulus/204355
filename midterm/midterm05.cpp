#include <bits/stdc++.h>
using namespace std;

#define long long long
#define REP(i,a,b) for (long i=a; i<=b; i++)

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long n, q, i1, i2, j1, j2, ans;
    cin >> n ;
    long arr[n][n], psa[n][n];
    REP(i,0,n-1) {
        REP(j,0,n-1) {
            cin >> arr[i][j];
        }
    }

    psa[0][0] = arr[0][0];
    REP (j,1,n-1) psa[0][j] = psa[0][j-1] + arr[0][j];
    REP (i,1,n-1) psa[i][0] = psa[i-1][0] + arr[i][0];
    REP (i,1,n-1) {
        REP (j,1,n-1) {
            psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + arr[i][j];
        }
    }

    cin >> q;
    REP(i,1,q) {
        cin >> i1 >> j1 >> i2 >> j2;
        ans = psa[i2][j2];
        if (i1>0) ans -= psa[i1-1][j2];
        if (j1>0) ans -= psa[i2][j1-1];
        if (i1>0 && j1>0) ans += psa[i1-1][j1-1];
        cout << ans << '\n';
    }
    return 0;
} 
