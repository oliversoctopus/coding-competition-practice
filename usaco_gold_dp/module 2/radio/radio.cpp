#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
dp[i][j] = min energy for farmer john at step i and bessie at step j (1-indexed)
dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + cost(i, j)
answer is dp[N][M]
*/

int cost(pair<int,int> c1, pair<int,int> c2) {
    return pow(abs(c1.first-c2.first), 2) + pow(abs(c1.second-c2.second), 2);
}

int main() {
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    int N, M;
    cin>>N>>M;
    pair<int,int> f_start;
    cin>>f_start.first>>f_start.second;
    pair<int,int> b_start;
    cin>>b_start.first>>b_start.second;

    vector<pair<int, int>> fj_path;
    string f_raw_path;
    cin >> f_raw_path;
    for (char c : f_raw_path) {
        if (c == 'N') {
            fj_path.push_back({0, 1});
        } else if (c == 'E') {
            fj_path.push_back({1, 0});
        } else if (c == 'W') {
            fj_path.push_back({-1, 0});
        } else {
            fj_path.push_back({0, -1});
        }
    }
    vector<pair<int, int>> bessie_path;
    string b_raw_path;
    cin >> b_raw_path;
    for (char c : b_raw_path) {
        if (c == 'N') {
            bessie_path.push_back({0, 1});
        } else if (c == 'E') {
            bessie_path.push_back({1, 0});
        } else if (c == 'W') {
            bessie_path.push_back({-1, 0});
        } else {
            bessie_path.push_back({0, -1});
        }
    }

    vector<pair<int, int>> fj_coords;
    fj_coords.push_back(f_start);
    pair<int, int> cur = f_start;
    for (int i = 0; i < N; i++) {
        cur.first += fj_path[i].first;
        cur.second += fj_path[i].second;
        pair<int, int> temp = cur;
        fj_coords.push_back(temp);
    }
    vector<pair<int, int>> bessie_coords;
    bessie_coords.push_back(b_start);
    cur = b_start;
    for (int i = 0; i < M; i++) {
        cur.first += bessie_path[i].first;
        cur.second += bessie_path[i].second;
        pair<int, int> temp = cur;
        bessie_coords.push_back(temp);
    }

    vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            int cur_cost = cost(fj_coords[i], bessie_coords[j]);
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
            } else if (i == 0) {
                dp[i][j] = dp[i][j-1] + cur_cost;
            } else if (j == 0) {
                dp[i][j] = dp[i-1][j] + cur_cost;
            } else {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + cur_cost;
            }
        }
    }
    cout << dp[N][M] << "\n";
}
