#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i=a; i<=b; i++)

long long threeSum(long long n) {
	return n * (n+1) * (n+2) / 6;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long long n;
    while (cin >> n) {
        cout << threeSum(n) << "\n";
    }
    return 0;
} 