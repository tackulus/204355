#include <bits/stdc++.h>
using namespace std;

#define long long long
#define REP(i,a,b) for (long i=a; i<=b; i++)

vector<int> pnr, S;

void backtrack(long k) {
    long last=pnr[-1]; pnr.pop_back();

    
    } while (next_permutation(pnr.begin(), pnr.end()));
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long k;

    cin >> k, x;
    REP (i,0,k-1) {cin >> x; S.push_back(x); pnr.push_back(i);}

    backtrack(k);

	return 0;
} 