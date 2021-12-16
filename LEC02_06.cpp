#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i=a; i<=b; i++)

long long result(long long n) {
	return ((n % (long long) (1e9 + 7)) * (n % (long long) (1e9 + 7))) % (long long) (1e9 + 7);
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long long n;
    while (cin >> n) {
        cout << result(n) << "\n";
    }
    return 0;
} 