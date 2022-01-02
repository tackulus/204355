#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i=a; i<=b; i++)

long long cost(priority_queue<long long, vector<long long>, greater<long long>> q) {
    long long ans=0, sum;
    while (q.size() > 1) {
        sum = 0;
        sum += q.top(); q.pop();
        sum += q.top(); q.pop();
        ans += sum;
        q.push(sum);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    long long n, x;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    cin >> n;
    REP(i, 1, n) {
        cin >> x;
        q.push(x);
    }
    cout << cost(q) << '\n';
    return 0;
} 