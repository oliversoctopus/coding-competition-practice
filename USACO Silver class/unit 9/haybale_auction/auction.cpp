/*
Notes: 
Why does hayb.lower_bound run thousands of times faster than lower_bound(hayb.begin(), hayb.end())?
Why does -O2 in compile make the program work 0.3s faster?
Why does the ifstream work 0.3s faster than freopen?
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;

void solve(const char* filename) {
    ifstream fin(filename);
    int n, m;
    fin >> n >> m;
    //cout << n << " " << m << endl;
    multiset<int> hayb;
    for (int i = 0; i < n; i++) {
        int val;
        fin >> val;
        hayb.insert(-val);
    }
    vector<int> cows(m);
    for (int i = 0; i < m; i++) {
        fin >> cows[i];
    }
    fin.close();
    //cout << "Running" << endl;
    ll ans = 0;
    for (int f : cows) {
        auto it = hayb.lower_bound(-f); // O(log n)
        if (it == hayb.end()) {
            ans--;
        } else {
            ans += -(*it);
            ans %= MOD;
            hayb.erase(it); // O(log n)
        }
    }
    cout << ans%MOD << "\n";
}

int main() {
    solve("01.in");
    solve("02.in");
    solve("03.in");
    solve("04.in");
    solve("05.in");
    solve("06.in");
    solve("07.in");
    solve("08.in");
    solve("09.in");
    solve("10.in");
}