/*
dp[i] = # of ways to make sequence with max_length=K-1 for a canvas of length i
dp[i+1] = dp[i]*M - dp[i+1-K]*M
dp[i] = dp[i-1]*M - dp[i-K]*(M-1)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);
    /**/
    ll MOD = 1e9+7;
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> dp (N+5); //real indexing so [3] gives u the amount of failures with length 3
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        int sub_ind = i-K;
        if (sub_ind < 0) {
            dp[i] = dp[i-1]*M;
            dp[i] %= MOD;
        } else if (sub_ind == 0) {
            dp[i] = dp[i-1]*M - dp[sub_ind] * M;
            dp[i] %= MOD;
        } else {
            //cout << i << " " << dp[i] << " " << dp[i-1] << " " << sub_ind << "\n";
            dp[i] = dp[i-1]*M - dp[sub_ind] * (M-1);
            dp[i] %= MOD;
        }
    }
    /*
    for (auto n : dp) {
        cout << n << " ";
    }*/
    //cout<<"\n";
    // M^N
    ll result = 1;
    for (int i = 0; i < N; i++) {
        result *= M;
        result %= MOD;
    }
    result -= dp[N];
    if (result < 0) {
        result += MOD;
    }
    result %= MOD;
    cout << result << "\n";
}
