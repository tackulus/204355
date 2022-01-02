#include <bits/stdc++.h>
using namespace std;

#define long long long
#define REP(i,a,b) for (int i=a; i<=b; i++)

string get_string() { return {}; }

void detect(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    auto si = s.begin();
    while (si != s.end()) {
        if (*si != ' ') {
            if (*si < 'a' || *si > 'z') *si = ' ';
        }
        si++;
    }

    stringstream ss(s);
    string word;
    set<string> dict;
    while (ss >> word) dict.insert(word);
    for (auto x:dict) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    string line, s = get_string();
    while (getline(cin, line)) s += line + ' ';
    detect(s);
    return 0;
} 