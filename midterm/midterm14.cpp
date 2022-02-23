#include <bits/stdc++.h>
using namespace std;

#define long long long
#define REP(i,a,b) for (long i=a; i<=b; i++)

set<long> moves={1};
long N, dp[10001];

long attack(long n) {
    if (n<0) return 0;
    if (n==0) return 1;
    if (dp[n]!=0) return dp[n];

    long ans=10001;
    for (auto x:moves) {
        long u = attack(n-x);
        if (u!=0) ans = min(ans,u);
    }

    return dp[n] = 1 + ans;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long k, a;

    cin >> N >> k;
    REP(i,1,k) {
        cin >> a;
        moves.insert(a);
    }
    for (auto x:moves) dp[x] = 1;
    cout << attack(N) << '\n';
	return 0;
} 