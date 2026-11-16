#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
here is the explanation
dp[i] = max profit from putting billboards up to the ith one (0-indexed)
dp[i+1] = max(dp[last compatible i]+v[i+1], dp[i])
*/
/*
In C++, std::lower_bound returns an iterator to the first element that is greater than or equal to the target value, 
while std::upper_bound returns an iterator to the first element that is strictly greater than the target value.
*/
void solve(const char* filename) {
    ifstream cin(filename);
    int n, t;
    cin>>n>>t;
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin>>pos[i];
    }
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        cin>>val[i];
    }

    vector<ll> dp(n);
    dp[0] = val[0];
    for (int i = 1; i < n; i++) {
        int compatible = distance(pos.begin(), lower_bound(pos.begin(), pos.end(), (ll)(pos[i]-t))) - 1;
        
        if (compatible == -1) {
            dp[i] = max((ll)val[i], dp[i-1]);
        } else {
            dp[i] = max(dp[compatible]+val[i], dp[i-1]);
        }
    }

    cout << dp[n-1] << endl;
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