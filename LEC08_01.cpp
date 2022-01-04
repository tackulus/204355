#include <bits/stdc++.h>
using namespace std;

#define long long long
#define REP(i,a,b) for (int i=a; i<=b; i++)

int tree[2048000]={0}, N;
string get_string() { return {}; }

void add(int k, int x) {
    k += N;
    tree[k] += x;
    for (k=k/2; k>=1; k/=2) tree[k] = tree[2*k] + tree[2*k+1];
}

void let(int idx, int x) {
    if ((tree[N+idx])!=x) {
        int u=x-tree[N+idx];
        add(idx, u);
    }
}

void change(int idx) { let(idx, 1-tree[N+idx]); }

int sum(int a, int b) {
    a += N; b += N;
    int s=0;
    while (a<=b) {
        if (a%2==1) s += tree[a++];
        if (b%2==0) s += tree[b--];
        a /= 2; b /= 2;
    }
    return s;
}

void command(char code, int a, int b) {
    if (code=='F') REP (i,a,b) { let(i,1); }
    else if (code=='E') REP (i,a,b) let(i,0);
    else if (code=='I') REP (i,a,b) change(i);
    else if (code=='S') cout << sum(a, b) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

    string input=get_string(), txt;
    int m, t, q, a, b;
    char code;

    // input part 1
    cin >> m;
    REP(i,1,m) {
        cin >> t >> txt;
        REP(j,1,t) input += txt;
    }
    N = input.length();
    REP (i,0,N-1) if (input[i]=='1') add(i, 1);
    
    // input part 2
    cin >> q;
    REP (i,1,q) {
        cin >> code >> a >> b;
        command(code, a, b);
    }
    return 0;
} 
