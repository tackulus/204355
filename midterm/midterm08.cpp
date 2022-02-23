#include <bits/stdc++.h>
using namespace std;

#define long long long
#define REP(i,a,b) for (long i=a; i<=b; i++)

vector<long> rows;
long hand=0, N, H;
bool doll=false;

void command(long c) {
    if (c==0) return;
    if (c==1) {
        if (hand!=0) hand--;
    }
    if (c==2) {
        if (hand!=N-1) hand++;
    }
    if (c==3) {
        if (doll) return;
        if (rows[hand]>0) {
            rows[hand]--;
            doll = true;
        }
    }
    if (c==4) {
        if (!doll) return;
        if (rows[hand]<H-1) {
            rows[hand]++;
            doll = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long x, c=1;
    cin >> N >> H;
    REP(i,1,N) {
        cin >> x;
        rows.push_back(x);
    }
    while (c!=0) {
        cin >> c;
        command(c);
    }

    for (auto x:rows) cout << x << " ";
	return 0;
} 