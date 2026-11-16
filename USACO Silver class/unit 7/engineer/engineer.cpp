#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(const char* filename) {
    auto begin = chrono::high_resolution_clock::now();
    ifstream cin(filename);
	int n, k;
    ll MOD = 1e9+7;
    cin >> n >> k;
    vector<vector<ll>> engineers;
    for (int i = 0; i < n; i++) {
        ll s, e;
        cin >> s >> e;
        engineers.push_back({e, s});
    }
    cin.close();
    sort(engineers.begin(), engineers.end());
    reverse(engineers.begin(), engineers.end());

    priority_queue<ll> cur_engineers;
    ll cur_count = 0;
    ll cur_sum = 0;
    vector<ll> max_speeds;
    for (int i = 0; i < n; i++) {
        ll cur_elem = engineers[i][1];
        if (cur_count < k) {
            cur_engineers.push(-cur_elem);
            cur_sum += cur_elem;
            cur_count++;
        } else {
            ll last = cur_engineers.top();
            cur_engineers.pop();
            if (-last < cur_elem) {
                cur_sum += cur_elem + last;
                cur_engineers.push(-cur_elem);
            } else {
                cur_engineers.push(last);
            }
        }
        max_speeds.push_back(cur_sum);
    }

    ll max = 0;
    for (int i = 0; i < n; i++) {
        ll cur = engineers[i][0];
        cur *= max_speeds[i];
        //cur %= MOD;
        if (cur > max) {
            max = cur;
        }
    }
    cout << max % MOD << endl;
    auto end = chrono::high_resolution_clock::now();
    auto microsecs = chrono::duration_cast<chrono::microseconds>(end - begin);
    double secs = microsecs.count() / 1000000.0;
    cout << "Time taken: " << secs << " seconds\n";
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