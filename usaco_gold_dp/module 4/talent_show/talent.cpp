#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool feasible(ll target, ll n, ll w, vector<ll>& talents, vector<ll>& weights) {
    vector<vector<ll>> dp(n+1, vector<ll>(w+1, -1e9));
    dp[0][0] = 0;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j <= w; j++) {
            ll curTotalWeight = j + weights[i];
            if (curTotalWeight > w) curTotalWeight = w;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]); // do nothing
            dp[i+1][curTotalWeight] = max(dp[i+1][curTotalWeight], dp[i][j] + talents[i] - target*weights[i]); // add cow
        }
    }

    return dp[n][w] >= 0;
}

int main() {
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    ll n, w;
    cin>>n>>w;
    vector<ll> talents(n);
    vector<ll> weights(n);
    for (ll i = 0; i < n; i++) {
        cin>>weights[i]>>talents[i];
    }
    for (ll i = 0; i < n; i++) {
        talents[i] = 1000*talents[i];
    }

    ll low = 0;
    ll high = 1e6;
    while (low < high) {
        ll mid = (low+high+1) / 2;
        if (feasible(mid, n, w, talents, weights)) {
            low = mid;
        } else {
            high = mid-1;
        }
    }
    cout << low << "\n";

}
