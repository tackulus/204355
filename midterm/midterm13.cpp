#include <bits/stdc++.h>
using namespace std;

#define long long long
#define REP(i,a,b) for (long i=a; i<=b; i++)

queue<long> circle;

long win(long n) {
	long u;
	while (!circle.empty()) circle.pop();
	REP(i,1,n) circle.push(i);
	while(circle.size() > 1) {
		u = circle.front(); circle.pop(); circle.push(u);
		circle.pop();
	}
	return circle.front();

}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long n;
	REP(i,1,5) {
		cin >> n;
		cout << win(n) << '\n';
	}
	return 0;
} 