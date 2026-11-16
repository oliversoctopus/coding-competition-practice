#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll x;
    cin>>n>>x;
    vector<vector<ll>> arr(n);
    for (int i = 0; i < n; i++) {
        vector<ll> temp(2);
        cin>>temp[0];
        temp[1] = i+1; // result indices need to be 1-indexed
        arr[i] = temp;
    }
    sort(arr.begin(), arr.end());
    bool success = false;
    for (int s = 0; s < n-2; s++) {
        ll remain = x - arr[s][0];
        int left = s+1;
        int right = n-1;
        while (left < right) {
            ll cur_s = arr[left][0] + arr[right][0];
            if (cur_s < remain) {
                // sum too small
                left++;
            } else if (cur_s > remain) {
                // sum too big
                right--;
            } else {
                // success!
                success = true;
                break;
            }
        }
        if (success) {
            cout << arr[s][1] << " " << arr[left][1] << " " << arr[right][1] << "\n";
            break;
        }
    }
    if (!success) cout << "IMPOSSIBLE\n";
}
