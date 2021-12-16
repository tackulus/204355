#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define REP(i,a,b) for (int i=a; i<=b; i++)

long long gcdSum(long long n) {
	long long result = 0;
	REP(i, 1, n-1) {
		REP(j, i+1, n) {
			result += __gcd(i, j);
		}
	}
	return result;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long long n;
    while (cin >> n) {
        cout << gcdSum(n) << "\n";
    }
    return 0;
} 