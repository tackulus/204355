#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i=a; i<=b; i++)

long long xSum(long long n) {
	return n * (n+1) * (2*n+1) / 6 + n * (n+1) / 2;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long long n;
    while (cin >> n) {
        cout << xSum(n) << "\n";
    }
    return 0;
} 