#include <bits/stdc++.h>
using namespace std;

#define long long long
#define REP(i,a,b) for (long i=a; i<=b; i++)

long decode(long k) {
    k *= 315; k += 36962;
    if (k<0) k *= -1;
    k /= 10;
    return (k%10);
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long t, k;
    cin >> t;
    REP(i,1,t) {
        cin >> k;
        cout << decode(k) << '\n';
    }

	return 0;
} 