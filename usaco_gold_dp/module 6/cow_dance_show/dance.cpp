/*
sort shows by end time, ascending
dp[k][i] = max value of watching k shows up to at most i (the latest show) 1-indexed
for each new show i:
    for each k:
        use binary search to find index i_old where end time is < start_time[i]
        dp[k+1][i] = dp[k][i_old] + value[i]

result = max of all dp[k][n-1]
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(const char* filename) {
    ifstream cin(filename);
    int N, K;
    cin>>N>>K;
    vector<vector<ll>> shows;
    vector<vector<ll>> dp(K+1, vector<ll>(N+1, 0));
    for (int i = 0; i < N; i++) {
        vector<ll> temp(3);
        cin>>temp[1]>>temp[0]>>temp[2];
        shows.push_back(temp);
    }
    cin.close();
    sort(shows.begin(), shows.end());
    
    vector<ll> starts(N);
    vector<ll> ends(N);
    vector<ll> values(N);
    for (int i = 0; i < N; i++) {
        starts[i] = shows[i][1];
        ends[i] = shows[i][0];
        values[i] = shows[i][2];
    }
    
    //dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        ll start = starts[i-1];
        ll end = ends[i-1];
        ll val = values[i-1];
        for (int k = 0; k < K; k++) {
            // lower bound: first element >= value
            // then subtract 1 from the iterator
            int ind = -1;
            auto it = lower_bound(ends.begin(), ends.end(), start);
            if (it == ends.begin()) ind = 0;
            else{
                auto new_it = prev(it);
                ind = distance(ends.begin(), new_it)+1; // 1-indexed
            }
            //cout << start << " " << end << " " << val << " " << ind << " " << i << "\n";
            dp[k][i] = max(dp[k][i], dp[k][i-1]);
            dp[k+1][i] = dp[k][ind] + val;
        }
        dp[K][i] = max(dp[K][i], dp[K][i-1]);
    }
    /*for (auto row : dp) {
        for (ll elem : row) {
            cout << elem << " ";
        }
        cout << "\n";
    }*/

    ll max_val = 0;
    for (int k = 1; k <= K; k++) {
        max_val = max(max_val, dp[k][N]);
    }
    cout << max_val << endl;
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

/* int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int N, K;
    cin>>N>>K;
    vector<vector<ll>> shows;
    vector<vector<ll>> dp(K+1, vector<ll>(N+1, 0));
    for (int i = 0; i < N; i++) {
        vector<ll> temp(3);
        cin>>temp[1]>>temp[0]>>temp[2];
        shows.push_back(temp);
    }
    sort(shows.begin(), shows.end());
    
    vector<ll> starts(N);
    vector<ll> ends(N);
    vector<ll> values(N);
    for (int i = 0; i < N; i++) {
        starts[i] = shows[i][1];
        ends[i] = shows[i][0];
        values[i] = shows[i][2];
    }
    
    //dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        ll start = starts[i-1];
        ll end = ends[i-1];
        ll val = values[i-1];
        for (int k = 0; k < K; k++) {
            // lower bound: first element >= value
            // then subtract 1 from the iterator
            int ind = -1;
            auto it = lower_bound(ends.begin(), ends.end(), start);
            if (it == ends.begin()) ind = 0;
            else{
                auto new_it = prev(it);
                ind = distance(ends.begin(), new_it)+1; // 1-indexed
            }
            //cout << start << " " << end << " " << val << " " << ind << " " << i << "\n";
            dp[k][i] = max(dp[k][i], dp[k][i-1]);
            dp[k+1][i] = dp[k][ind] + val;
        }
        dp[K][i] = max(dp[K][i], dp[K][i-1]);
    }
    /*for (auto row : dp) {
        for (ll elem : row) {
            cout << elem << " ";
        }
        cout << "\n";
    }

    ll max_val = 0;
    for (int k = 1; k <= K; k++) {
        max_val = max(max_val, dp[k][N]);
    }
    cout << max_val << endl;
} */