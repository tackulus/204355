#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define REP(i,a,b) for (int i=a; i<=b; i++)
#define MAX 100

long long maxGCD(long long res[], long long n) {
	long long ans = __gcd(res[0], res[1]);
	REP(i, 0, n-1) {
		REP(j, i+1, n-1) {
			ans = max(ans, __gcd(res[i], res[j]));
		}
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long long x, res[MAX], n = 0;
    while (cin >> x) res[n++] = x;
	cout << maxGCD(res, n) << "\n";
    return 0;
} 