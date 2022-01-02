#include <bits/stdc++.h>
using namespace std;

#define long long long
#define REP(i,a,b) for (int i=a; i<=b; i++)

long lookup[100000][17];

int query(long arrmax[], long L, long R) {
    int j = (int)log2(R-L+1);
    long x = arrmax[lookup[L][j]], 
         y = arrmax[lookup[R-(int)pow(2,j)+1][j]];
    return x >= y ? x : y;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long n, m, a, b;
    cin >> n >> m;
    long arrmax[n], arrsum[n];
    REP(i,0,n-1) {
        lookup[i][0] = i;
        cin >> arrmax[i];
    }
    for (int j=1; (1<<j)<=n; j++) for (int i=0; (i+(1<<j)-1) < n; i++) {
        long x = lookup[i][j-1], 
             y = lookup[i + (1<<(j-1))][j-1];
        lookup[i][j] = arrmax[x] > arrmax[y] ? x : y; 
    }
    REP(i,0,n-1) {
        cin >> arrsum[i];
        if (i!=0) arrsum[i] += arrsum[i-1];
    }

    REP(i,1,m) {
        cin >> a >> b;
        cout << query(arrmax, a, b) << " ";
        if (a!=0) cout << arrsum[b] - arrsum[a-1] << '\n';
        else cout << arrsum[b] << '\n';
    }
    return 0;
} 
