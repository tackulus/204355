#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i=a; i<=b; i++)

int Calculate(int n) {
    if (n==1) return 1;
    int printerDay = floor(log2(n));
    int ans = printerDay + ceil((float) n / (float) exp2(printerDay));
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n;
	while (cin >> n) {
		cout << Calculate(n) << "\n";
	}
    return 0;
} 