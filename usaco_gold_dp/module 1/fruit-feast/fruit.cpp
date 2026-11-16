#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int t, a, b;
    cin>>t>>a>>b;
    vector<bool> achievable (t+1, false); //numbers where a linear combination of apples and oranges can reach fullness
    int x = max(a, b);
    int y = min(a, b);
    unordered_set<int> rems;
    int rem = 0;
    for (int k = 0; k <= t/x; k++) {
        if (rems.count(rem)) break;
        for (int i = k*x; i <= t; i+=y) {
            achievable[i] = true;
        }
        rems.insert(rem);
        rem += x;
        rem %= y;
    }
    //cout << "step 1\n";

    vector<int> dp(t+1, 0);
    for (int i = t-x+1; i <= t; i++) {
        dp[i] = t - (t-i)%y;
    }
    int k = (t-x+1) - y;
    while (k >= -y) {
        for (int i = max(k, 0); i <= k+y; i++) {
            dp[i] = max(dp[i+x], dp[i+y]);
        }
        k-=y;
    }
    //cout << "step 2\n";

    int result = 0;
    for (int i = t; i >= 0; i--) {
        if (achievable[i]) {
            result = i; 
            break;
        }
    }
    for (int i = 0; i <= t; i++) {
        if (achievable[i]) {
            if (dp[i/2] > result) {
                result = dp[i/2];
            }
        }
    }
    cout << result << "\n";
}