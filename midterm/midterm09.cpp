#include <bits/stdc++.h>
using namespace std;

#define long long long
#define REP(i,a,b) for (long i=a; i<=b; i++)

long llreverse(long x) {
	long ans=0;
	while(x>0) {
		ans *= 10; ans += x%10;
		x /= 10;
	}
	return ans;
}

void palindrome(long x) {
	if (x==llreverse(x)) {cout << 0 << " " << x << '\n'; return;}
	long y;
	REP(t,1,1000) {
		y = llreverse(x);
		x += y;
		y = llreverse(x);
		if (x==y) {cout << t << " " << x << '\n'; return;}
	}
	return;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long n, x;
	cin >> n;
	REP(i,1,n) {
		cin >> x;
		palindrome(x);
	}
	return 0;
} 