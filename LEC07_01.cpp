#include <bits/stdc++.h>
using namespace std;

#define long long long
#define REP(i,a,b) for (int i=a; i<=b; i++)

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long n, m, a, b;
    cin >> n >> m;
    long array[n];
    REP(i,0,n-1) {
        cin >> array[i];
        if (i!=0) array[i] += array[i-1];
    }
    REP(i,1,m) {
        cin >> a >> b;
        if (a!=0) cout << array[b] - array[a-1] << '\n';
        else cout << array[b] << '\n';
    }
    return 0;
} 
