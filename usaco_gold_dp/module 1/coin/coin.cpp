#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
dp[v] = # of ways to produce v with coins up to coin #i
dp[v+c_i] += dp[v]

iterate over all i
*/
void solve(const char* filename) {
    ifstream cin(filename);
    ll MOD = 1e9+7;
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin>>coins[i];
    }
    sort(coins.begin(), coins.end());
    vector<ll> dp(x+5);
    dp[0] = 1;
    for (int c : coins) {
        for (int v = 0; v <= x-c; v++) {
            dp[v+c] += dp[v];
            dp[v] %= MOD;
        }
    }
    /*
    for (int i = 0; i <= x; i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";*/
    cout << dp[x] << "\n";
    cin.close();
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

/* int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll MOD = 1e9+7;
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin>>coins[i];
    }
    sort(coins.begin(), coins.end());
    vector<ll> dp(x+5);
    dp[0] = 1;
    for (int c : coins) {
        for (int v = 0; v <= x-c; v++) {
            dp[v+c] += dp[v];
        }
    }
    cout << dp[x] << "\n";
}
 */