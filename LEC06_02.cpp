#include <bits/stdc++.h>
using namespace std;

#define long long long
#define REP(i,a,b) for (int i=a; i<=b; i++)

long tournament(deque<bool> q) {
    long ans = 0;
    bool a, b;
    while (q.size() != 1) {
        a = q.front(); q.pop_front();
        b = q.front(); q.pop_front();
        q.push_back(a or b);
        if (a xor b) ans++;
    }
    return ans;
} 

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long n, m, x;
    cin >> n >> m;
    deque<bool> q(exp2(n), true);
    REP(i, 1, m) {
        cin >> x;
        q[x-1] = false;
    }
    cout << tournament(q) << '\n';
    return 0;
} 