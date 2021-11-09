#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i=a; i<=b; i++)
#define MAX 160

int multiply(int x, int res[], int res_ptr) {
    int carry = 0;

    REP(i, 0, res_ptr-1) {
        int prod = res[i] * x + carry;
        res[i] = prod % 10; 
        carry  = prod / 10;  
    }
    while (carry) {
        res[res_ptr++] = carry % 10;
        carry = carry / 10;
    }

    return res_ptr;
}

string factorial(int n) {
    int res[MAX];
    res[0] = 1;
    int res_ptr = 1;

    REP(x, 2, n) res_ptr = multiply(x, res, res_ptr);

    string str;
    for (int i=res_ptr-1; i>=0; i--) str = str + to_string(res[i]);
    return str;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n;
    while (cin >> n) {
        cout << factorial(n) << "\n";
    }
    return 0;
} 