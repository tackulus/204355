#include <bits/stdc++.h>
using namespace std;

#define long long long
#define REP(i,a,b) for (long i=a; i<=b; i++)

map<string,long> sensors;

long gcd(long a, long b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

void simulate(long k) {
    long time=0, globalGCD;
    for (auto pair:sensors) {globalGCD = pair.second; break;}
    for (auto pair:sensors) {globalGCD = gcd(globalGCD, pair.second);}
    while (k>0) {
        time += globalGCD;
        for (auto pair:sensors) {
            if ((time%pair.second==0) & (k>0)) {
                cout << time << " " << pair.first << '\n';
                k--;
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    string name;
    long n, k, t;

    cin >> n >> k;
    REP(i,1,n) {
        cin >> name >> t;
        sensors[name] = t;
    }
    simulate(k);
	return 0;
} 