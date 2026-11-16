#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
dp[a][b] = inversions in subarray [a, b]
dp[a][b] = dp[a+1][b] + dp[a][b-1] - dp[a+1][b-1] + (1 if a, b is inversion)
a goes down
b goes up
*/

void solve(const char* filename) {
    ifstream cin(filename);
    int MOD = 1e9+7;
    int N, Q;
    cin>>N>>Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    vector<vector<int>> dp (N, vector<int>(N, 0));
    for (int a = N-2; a >= 0; a--) {
        for (int b = a+1; b < N; b++) {
            dp[a][b] = dp[a+1][b] + dp[a][b-1] - dp[a+1][b-1] + (arr[a] > arr[b]);
            dp[a][b] %= MOD;
        }
    }

    int sum = 0;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin>>L>>R;
        sum += dp[L-1][R-1];
        sum %= MOD;
    }
    cout << sum << "\n";
    cin.close();
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
/* 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N, Q;
    cin>>N>>Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    vector<vector<int>> dp (N, vector<int>(N, 0));
    for (int a = N-2; a >= 0; a--) {
        for (int b = a+1; b < N; b++) {
            dp[a][b] = dp[a+1][b] + dp[a][b-1] - dp[a+1][b-1] + (arr[a] > arr[b]);
        }
    }

    for (int i = 0; i < Q; i++) {
        int L, R;
        cin>>L>>R;
        cout << dp[L-1][R-1] << "\n";
    }
} */