#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fac(ll n, ll mod) {
    ll product = 1;
    for (ll i = 1; i <= n; i++) {
        product *= i;
        product %= mod;
    }
    return product;
}

ll modpow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll modinv(ll x, ll mod) {
    return modpow(x, mod - 2, mod);
}

void solve(const char* filename) {
    ifstream cin(filename);
    const ll MOD = 1e9 + 7;
    ll n;
    cin>>n;
    vector<ll> t(n);
    for (ll i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());
    ll diff = t[t.size() - 1] - t[t.size() - 2];

    if (diff >= 2) {
        cout << 0 << endl << flush;
    } else if (diff == 1) {
        cout << "\ndiff = 1\n";
        int cnt_sec = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == t[t.size() - 2]) {
                cnt_sec++;
            }
        }
        
        ll subtract = fac(n, MOD) * modinv(cnt_sec + 1, MOD);
        subtract %= MOD;
        ll res = fac(n, MOD) - subtract;
        if (res < 0) {
            res += MOD;
        }
        cout << res << endl << flush;
    } else {
        cout << fac(n, MOD) << endl << flush;
    }
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