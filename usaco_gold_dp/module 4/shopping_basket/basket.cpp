#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(const char* filename) {
    ifstream cin(filename);
    int s, n;
    cin>>s>>n;
    vector<int> V(n);
    vector<int> W(n);
    vector<int> K(n);
    for (int i = 0; i < n; i++) {
        cin>>V[i];
        cin>>W[i];
        cin>>K[i];
    }
    cin.close();

    vector<int> prev_dp(s+1);
    vector<int> dp(s+1);
    for (int i = 0; i < n; i++) {
        int w = W[i];
        int v = V[i];
        int k = min(K[i], s/w);

        if (k == 0 || w > s) continue;

        for (int j = 0; j <= s; j++) {
            prev_dp[j] = dp[j];
        }
        
        // remainders
        for (int r = 0; r < w; r++) {
            // pairs: (normalized_value, track_index)
            // track_index = index of element in list of all things with remainder r
            deque<pair<int,int>> q;

            int max_steps = (s-r) / w;
            for (int choice = 0; choice <= max_steps; choice++) {
                int cur_capacity = r + choice * w;
                int normalized = prev_dp[cur_capacity] - choice * v;
                while (q.size() > 0 && q.back().first <= normalized) {
                    q.pop_back();
                }

                q.push_back({normalized, choice});

                while (q.front().second < choice-k) {
                    q.pop_front();
                }

                //cout << cur_capacity << " " << q.front().first + choice*v << "\n";
                dp[cur_capacity] = q.front().first + choice*v;
            }
        }
    }
    cout << dp[s] << "\n";
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