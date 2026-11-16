#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int n;
    cin>>n;
    vector<int> barns(n);
    for (int i=0; i<n; i++) cin>>barns[i];
    // Get looped barns so we can simulate rotations easily (just go forwards)
    vector<int> looped_barns(n*2);
    for (int i = 0; i < n; i++) {
        looped_barns[i] = barns[i];
        looped_barns[i+n] = barns[i];
    }

    // Simulate each rotation (n=1000 so n^2 is fine)
    ll min_dist = LLONG_MAX;
    for (int start = 0; start < n; start++) {
        ll cur_dist = 0;
        for (int i = start+1; i < start+n; i++) {
            cur_dist += looped_barns[i]*(i-start);
        }
        if (cur_dist < min_dist) min_dist = cur_dist;
    }
    cout << min_dist << endl;
}