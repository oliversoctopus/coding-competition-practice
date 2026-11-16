/*Precompute the # of ways to get a K-syllable line ending in rhyme class i for all i
for each i in rhyme class:
    res = 0
    for each end_word in (list of all words with rhyme class i):
        n_syllables = K - syllables[end_word]
        solve for # of ways to get n_syllables using this list
    res += (sol)
    arr[i] = res


Then for each available rhyme scheme requirement (A, B, C, etc) with # of occurrences n, do:
ans *= sum([i^n for i in precomputed_list])
ans %= 1e9+7


for # of ways to get n_syllables:
dp[k] = # of combinations with k syllables
dp[k] = sum(dp[k-s] for all s in (list of syllables of words))
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod_pow(ll a, ll b, ll MOD) {
    ll result = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2 == 1) {
            b--;
            result *= a;
            result %= MOD;
        }
        b /= 2;
        a = (a * a) % MOD;
    }
    return result;
}

int main() {
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    int N, M, K;
    int MOD = 1e9+7;
    cin>>N>>M>>K;
    
    vector<vector<ll>> rhyme(N, vector<ll>(0)); //syllables, rhyme class
    vector<ll> words(N);
    for (int i = 0; i < N; i++) {
        ll s, c;
        cin>>s>>c;
        rhyme[c-1].push_back(s);
        words[i] = s;
    }
    sort(words.begin(), words.end());
    
    vector<ll> rhyme_schemes(26);
    for (int i = 0; i < M; i++) {
        char r;
        cin>>r;
        int temp = r - 'A';
        rhyme_schemes[temp]++;
    }

    vector<ll> dp(K+1, 0);
    dp[0] = 1;
    for (int i = 0; i <= K; i++) {
        dp[i] %= MOD;
        for (ll s : words) {
            if (i+s > K) break;
            dp[i+s] += dp[i];
            dp[i+s] %= MOD;
        }
    }

    vector<ll> n_ways(N); // n_ways[i] is the number of ways to get a K-syllable line that ends in rhyme class i
    for (int i = 0; i < N; i++) {
        if (rhyme[i].size() == 0) continue;
        ll res = 0;
        for (ll word : rhyme[i]) {
            ll n_syllables = K - word;
            res += dp[n_syllables]; // number of ways to get n_syllables syllables with arbitrary string of words
            res %= MOD;
        }
        n_ways[i] = res;
    }

    ll answer = 1;
    for (ll scheme : rhyme_schemes) {
        if (scheme == 0) continue;
        ll cur_sum = 0;
        for (ll n : n_ways) {
            cur_sum += mod_pow(n, scheme, MOD);
            cur_sum %= MOD;
        }
        answer *= cur_sum;
        answer %= MOD;
    }
    cout << answer;
}
