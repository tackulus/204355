#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for (int i=a; i<=b; i++)

string get_string() { return {}; } 

string fix(string s) {
    string cut = get_string(), ans = get_string();
    stack<string> st;
    bool state = false;
    for (auto x : s) {
        if (x == '[') {
            st.push(cut);
            cut = get_string();
            state = true;
        }
        else if (x == ']') {
            st.push(cut);
            cut = get_string();
            state = false;
        }
        else if (state) cut += x;
        else ans += x;
    }
    st.push(cut);
    cut = get_string();
    while (!st.empty()) {
        cut += st.top();
        st.pop();
    }
    
    return (cut + ans);
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    string s;
    cin >> s;
    cout << fix(s) << '\n';
    return 0;
} 