// cow_checkups.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> b[i];
    }

    unordered_map<int, vector<int>> a_positions;
    for (int j = 1; j <= N; ++j) {
        a_positions[a[j]].push_back(j);
    }

    unordered_map<int, pair<vector<int>, vector<ll>>> processed;
    for (auto& entry : a_positions) {
        int v = entry.first;
        vector<int>& positions = entry.second;
        sort(positions.begin(), positions.end());
        vector<ll> prefix_sums;
        prefix_sums.push_back(0);
        ll sum = 0;
        for (int j : positions) {
            sum += j;
            prefix_sums.push_back(sum);
        }
        processed[v] = { positions, prefix_sums };
    }

    ll total = 0;

    for (int i = 1; i <= N; ++i) {
        ll total_i = 0;

        // First part contribution
        if (a[i] == b[i]) {
            ll left = (i - 1) * i / 2;
            ll right = (N - i) * (N - i + 1) / 2;
            total_i += left + right;
        }

        // Second part contribution
        int v = b[i];
        auto it = processed.find(v);
        if (it != processed.end()) {
            const vector<int>& S = it->second.first;
            const vector<ll>& prefix_sums = it->second.second;
            int m = S.size();

            // Group1a: j >=i, j <=X = min(N, N+1 -i)
            int X = min(N, (N + 1) - i);
            auto it_low = lower_bound(S.begin(), S.end(), i);
            auto it_high = upper_bound(S.begin(), S.end(), X);
            int count1a = it_high - it_low;
            ll group1a = (ll)count1a * i;

            // Group1b: j >=Y = max(i, N+2 -i)
            int Y = max(i, (N + 2) - i);
            ll group1b = 0;
            if (Y <= N) {
                auto it_pos = lower_bound(S.begin(), S.end(), Y);
                int cnt = S.end() - it_pos;
                if (cnt > 0) {
                    int pos = it_pos - S.begin();
                    ll sum_j = prefix_sums.back() - prefix_sums[pos];
                    group1b = (ll)(N + 1) * cnt - sum_j;
                }
            }

            // Group2a: j <=Z = min(i-1, N+1 -i)
            int Z = min(i - 1, (N + 1) - i);
            ll group2a = 0;
            if (Z >= 0) {
                auto it_high_z = upper_bound(S.begin(), S.end(), Z);
                int pos = it_high_z - S.begin();
                group2a = prefix_sums[pos];
            }

            // Group2b: j > Z and j <i
            ll group2b = 0;
            int lower = Z + 1;
            int upper = i - 1;
            if (lower <= upper) {
                auto it_low_b = lower_bound(S.begin(), S.end(), lower);
                auto it_high_b = upper_bound(S.begin(), S.end(), upper);
                int cnt = it_high_b - it_low_b;
                group2b = (ll)cnt * (N - i + 1);
            }

            total_i += group1a + group1b + group2a + group2b;
        }

        total += total_i;
    }

    cout << total << '\n';

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
