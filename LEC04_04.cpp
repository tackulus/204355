#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i=a; i<=b; i++)

bool comp(pair<int, int> lhs, pair<int, int> rhs) {
    if (lhs.second != rhs.second) return lhs.second < rhs.second;
    else return lhs.first < rhs.first;
}

int prev_runable(vector<pair<int,int>> v, int idx) {
    int l = 0, r = idx - 1;
    while (l <= r) {
        int cur = (l + r) / 2;
        if (v[cur].second <= v[idx].first) {
            if (cur == idx - 1 || v[cur + 1].second > v[idx].first)
                return cur;
            l = cur + 1;
        }
        else r = cur - 1;
    }
    return -1;
}

int schedule(vector<pair<int,int>> v) {
    int n = v.size();
    int ansCol[n];
    ansCol[0] = 1;

    if (n == 0) return 0;

    sort(v.begin(), v.end(), comp);
    
    REP(i, 1, n-1) {
        int prev_idx = prev_runable(v, i);
        if (prev_idx != -1) ansCol[i] = 1 + ansCol[prev_idx];
        else ansCol[i] = 1;
        ansCol[i] = max(ansCol[i], ansCol[i-1]);
    }
    return ansCol[n-1];
}
int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n;
    vector<pair<int,int>> v;
    pair<int,int> u;
    cin >> n;
    REP(i, 1, n) {
        cin >> u.first >> u.second;
        v.push_back(u);
    }

    cout << schedule(v) << '\n';
    return 0;
} 