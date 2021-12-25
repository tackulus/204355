#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i=a; i<=b; i++)

void SoE(int n) {
	bool prime[n+1];
	memset(prime, true, sizeof(prime)); 
	for (int p=2; p*p<=n; p++) { 
		if (prime[p] == true) { 
			// Update all multiples of p 
			for (int i=p*2; i<=n; i += p)
				prime[i] = false;
			
		} 
	}
    
	// Print all prime numbers
	REP(p, 2, n) 
		if (prime[p]) 
			cout << p << " ";
    
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n;
	while (cin >> n) {
		SoE(n);
	}
    return 0;
} 