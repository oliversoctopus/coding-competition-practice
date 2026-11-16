#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int c;
        cin>>c;
        if (c == 1) {
            arr.push_back(1);
        } else {
            arr.push_back(-1);
        }
    }

    vector<int> psum;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            psum.push_back(arr[i]);
        } else {
            psum.push_back(arr[i] + psum[i - 1]);
        }
    }

    map<int, int> mp;
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (mp.count(psum[i])) {
            result = max(result, i - mp[psum[i]]);
        } else {
            mp[psum[i]] = i;
        }
    }
    cout << result << endl;
}
