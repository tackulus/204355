#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i=a; i<=b; i++)

int RangeSoE(int a, int b) {
	bool prime[b+1];
	memset(prime, true, sizeof(prime)); 
	for (int p=2; p*p<=b; p++) { 
		if (prime[p] == true) { 
			// Update all multiples of p 
			for (int i=p*2; i<=b; i += p)
				prime[i] = false;
			
		} 
	}
    
	// Count prime numbers in (a,b)
	int COUNT = 0;
    REP(p, a, b) 
		if (prime[p]) 
			COUNT++;
	
    return COUNT;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    int a, b;
	while (cin >> a >> b) {
		cout << RangeSoE(a, b);
	}
    return 0;
} 