#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
dp[i] = optimal solution up to cow i
dp[i] = max(dp[i-k] + max(last group of cows)*k, dp[i-k+1] + max(last)*(k-1), ..., dp[i-1] + max(cows[i])*(1) )
get the group of cows from index i-k+1 to i
put them in a set
to get max, read the top of the set
set.remove(c[i-k+1])
read top again
repeat
*/

int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    if (K > N) {
        K = N;
    }
    vector<ll> cows(N);
    for (int i = 0; i < N; i++) {
        cin>>cows[i];
    }
    vector<ll> dp(N); // 0 indexed
    ll cur_max = 0;
    for (int i = 0; i < K; i++) {
        cur_max = max(cur_max, cows[i]);
        dp[i] = cur_max * (i+1);
    }

    for (int i = K; i < N; i++) {
        ll cur_max = 0;
        ll max_cow = 0;
        for (int block = 1; block <= K; block++) {
            //cout << i << " " << block << "\n";
            max_cow = max(max_cow, cows[i-block+1]);
            ll cur_val = dp[i-block] + max_cow * block;
            cur_max = max(cur_max, cur_val);
        }
        dp[i] = cur_max;
    }
    cout << dp[N-1];
}