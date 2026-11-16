#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

void solve(const char* filename) {
    ifstream cin(filename);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin>>n>>k;
    vector<pair<ll,ll>> engineers(n); // {efficiency, speed}
    for (int i = 0; i < n; i++) {
        cin>>engineers[i].second>>engineers[i].first;
    }
    cin.close();
    sort(engineers.begin(), engineers.end());

    priority_queue<ll> speeds;
    vector<ll> psum(n+1);
    for (int i = n-1; i > 0; i--) {
        // push and pop negative values because max priority queue
        if (speeds.size() < k) {
            speeds.push(-engineers[i].second);
            psum[i] = psum[i+1] + engineers[i].second;
        } else {
            ll worst = -speeds.top();
            if (worst < engineers[i].second) {
                speeds.pop();
                speeds.push(-engineers[i].second);
                psum[i] = psum[i+1] - worst + engineers[i].second;
            } else {
                psum[i] = psum[i+1];
            }
        }
    }

    ll max_performance = -1;
    for (int i = 0; i < n; i++) {
        ll cur = engineers[i].first * psum[i];
        if (cur > max_performance) {
            max_performance = cur;
        }
    }
    cout << max_performance%MOD << "\n";
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