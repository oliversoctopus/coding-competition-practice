#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // get data
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<int> q(n);
    for (int i = 0; i < n; i++) {
        cin>>q[i];
    }
    vector<pair<int, int>> conditions;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin>>a>>b;
        conditions.push_back({a, b});
    }

    // initialize result as the quietness of the person himself
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = q[i];
    }
    // for every condition, b "inherits" a's minimum quietness because a is richer than b
    for (int i = 0; i < m; i++) {
        int a = conditions[i].first;
        int b = conditions[i].second;
        res[b] = min(res[b], res[a]);
    }
    // Print final result
    for (int i = 0; i < n; i++) {
        cout << res[i] << "\n";
    }
}
