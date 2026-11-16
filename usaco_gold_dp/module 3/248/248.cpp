#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
Take all the subarrays of length 1, store them
Increase subarray length
Check each one of them, split down the middle at every possible index,
and see if the left+right reduce to individual numbers
Store the result as the maximum individual number it can reduce to,
or 0 if it can't reduce
The final answer is the maximum individual reducible number across 
all possible subarrays which is O(N^2)
*/
int main() {
    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);
    int N;
    cin>>N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin>>nums[i];
    }
    vector<vector<int>> dp(N, vector<int> (N, 0)); //no unique number: 0
    // dp measures the subarray inclusive
    for (int len = 1; len <= N; len++) {
        for (int i = 0; i <= N-len; i++) {
            int j = i+len-1;
            if (i == j) {
                dp[i][j] = nums[i];
            } else {
                for (int split = i+1; split <= j; split++){
                    // all indices < split are on the left, everything else is on the right
                    int left = dp[i][split-1];
                    int right = dp[split][j];
                    if (left == right){
                        dp[i][j] = max(dp[i][j], left+1);
                    }
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            answer = max(answer, dp[i][j]);
        }
    }
    cout << answer << "\n";
}