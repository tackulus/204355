#include <bits/stdc++.h>
using namespace std;

#define long long long
#define REP(i,a,b) for (long i=a; i<=b; i++)

bool checkX(long x, long a, long b, long c) { 
    return ( (2 * pow(x,2) * (a-x) + 2 * b) == ((pow(a,2) - c) * x) );
}

bool checkY(long y, long x, long a, long b) { 
    return ( (x * pow(y,2) + b) == ((a - x) * x * y) );
}

void backtrack(long a, long b, long c) {
    REP (x, -10000, 10000) if (checkX(x,a,b,c)) {
        REP (y, -10000, 10000) if (checkY(y,x,a,b)) {
            if (y==x) continue;
            long z = a - x - y;
            if (z==x | z==y) continue;
            if (x+y+z != a) continue;
            if (x*y*z != b) continue;
            if (pow(x,2) + pow(y,2) + pow(z,2) != c) continue;
            cout << x << " " << y << " " << z;
            return;
        }
    }
    cout << "No solution.";
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long a, b, c;

    cin >> a >> b >> c;
    backtrack(a, b, c);
	return 0;
} 