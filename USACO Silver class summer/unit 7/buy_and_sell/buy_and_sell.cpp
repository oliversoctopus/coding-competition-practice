#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    vector<int> pref_min;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            pref_min.push_back(arr[i]);
        } else {
            pref_min.push_back(min(arr[i], pref_min[i - 1]));
        }
    }
    vector<int> suff_max(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            suff_max[i] = arr[i];
        } else {
            suff_max[i] = max(suff_max[i + 1], arr[i]);
        }
    }

    vector<int> p_profit(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            p_profit[i] = 0;
        } else {
            p_profit[i] = max(p_profit[i - 1], arr[i] - pref_min[i]);
        }
    }
    vector<int> s_profit(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            s_profit[i] = 0;
        } else {
            s_profit[i] = max(s_profit[i + 1], suff_max[i] - arr[i]);
        }
    }

    int res = p_profit[0];
    for (int i = 0; i < n; i++) {
        res = max(res, p_profit[i] + s_profit[i]);
    }
    cout << res << endl;
}
