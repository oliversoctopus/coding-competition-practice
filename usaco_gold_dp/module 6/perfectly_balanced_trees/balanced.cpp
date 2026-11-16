#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

// Goes to stderr NOT stdout and only active with -DLOCAL. Ex: dbg(x) prints "x = value  ".
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << "  "
#define dbgln(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#define dbgln(x)
#endif

ll MOD = 1e9+7;
unordered_map<ll, ll> dp;
ll num_ways(int N) {
    if (N == 1) {
        dp[N] = 1;
        return 1;
    }
    if (dp.count(N)) { return dp[N]; }
    vector<ll> change;
    ll val = 1;
    while (val <= N) {
        ll m = N / val; // subtree weight
        ll maxV = N / m; // max # subtrees to keep this weight
        change.push_back(val);
        val = maxV + 1;
    }
    change.push_back(val); // upper bound to include case of subtrees w/ size 1
    /* dbgln(N);
    for (ll v : change) {
        cout << v << " ";
    }
    cout << "\n"; */

    ll sum = 0;
    for (int i = 2; i < change.size(); i++) {
        sum += (change[i] - change[i-1]) * num_ways(N / change[i-1]);
        sum %= MOD;
    }
    //dbgln(sum);
    dp[N] = sum;
    return dp[N];
}

// To read file, call setIO("filename")
void setIO(const string& name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        (void)!freopen((name + ".in").c_str(), "r", stdin);
        (void)!freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() {
    int N;
    cin>>N;
    cout << num_ways(N) << "\n";
}

int main() {
    setIO();
    solve();
}