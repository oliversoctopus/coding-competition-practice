#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin>>n>>k;
    vector<int> nums(n);
    for (int j = 0; j < n; j++) {
        cin>>nums[j];
        nums[j] = __gcd(nums[j], k);
    }

    unordered_map<int, int> m;
    ll ans = 0;
    for (ll x : nums) {
        for (const auto& p : m) {
            if (x * p.first % k == 0)
                ans += p.second;
        }
        m[x]++;
    }
    cout << ans << "\n";
    return 0;
}
