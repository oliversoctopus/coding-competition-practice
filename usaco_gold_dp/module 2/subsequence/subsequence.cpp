#include <bits/stdc++.h>    
using namespace std;
typedef long long ll;

void solve(const char* filename) {
    ifstream cin(filename);
    int N;
    cin>>N;
    vector<int> numbers(N);
    for (int i = 0; i < N; i++){
        cin >> numbers[i];
    }
    cin.close();
    int answer = 1;
    vector<int> dedup;
    int prev = 0;
    int cur_len = 0;
    for (int n : numbers) {
        if (prev == 0) {
            prev = n;
            cur_len = 1;
            dedup.push_back(n);
        } else {
            if (n != prev) {
                answer = max(answer, cur_len);
                cur_len = 1;
                prev = n;
                dedup.push_back(n);
            } else {
                cur_len++;
            }
        }
    }
    answer = max(answer, cur_len);
    N = dedup.size();

    vector<vector<int>> dp(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            dp[i][j] = 2;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int d = (dedup[j] - dedup[i]) / (dp[i][j]-1); // common difference
            auto it = lower_bound(dedup.begin(), dedup.end(), dedup[j]+d);
            if (it != dedup.end() && *it == dedup[j]+d) {
                int ind = distance(dedup.begin(), it);
                dp[i][ind] = max(dp[i][j]+1, dp[i][ind]);
            }
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            answer = max(answer, dp[i][j]);
        }
    }
    cout << answer << "\n";
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