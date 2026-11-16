/*
ex:
actual cuts [4, 5, 7, 8]
add 0 to beginning and 10 to end
work with [0, 4, 5, 7, 8, 10]
dp[0][5] = 10 + (min)

dp[n1][n2] = cost of cutting with bounds of n1 and n2
dp[i][j] initially instantiated to 1e6
dp[i][j] = (j-i) + (min over all k of dp[i][k] + dp[k][j] subject to i<k<j)

n = len(cuts_plus_bounds)
for i from 0 to n-1:
    dp[i][i] = 0
for w from 0 to n-1:
    for i from 0 to n-w-1:
        j = i + w
        for k from i+1 to j-1:
              dp[i][j] = min(dp[i][j], (pos[j] - pos[i]) + dp[i][k] + d[k][j])
return dp[0][n]
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(const char* filename) {
    ifstream cin(filename);
    int Q;
    cin >> Q;
    int result = 0;
    while (Q-- > 0)
    {
        int L, N;
        cin >> L >> N;
        vector<int> pos;
        pos.push_back(0);
        for (int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            pos.push_back(temp);
        }
        pos.push_back(L);
        N += 2;

        vector<vector<int>> dp(N, vector<int>(N, 1e6));
        for (int i = 0; i < N; i++) 
            dp[i][i] = 0;
        for (int i = 0; i < N-1; i++)
            dp[i][i+1] = 0;
        for (int w = 2; w < N; w++)
        {
            for (int i = 0; i < N - w; i++) {
                int j = i + w;
                int min_val = 1e6;
                for (int k = i+1; k < j; k++) {
                    min_val = min(min_val, dp[i][k] + dp[k][j]);
                }
                dp[i][j] = min(dp[i][j], (pos[j] - pos[i]) + min_val);
            }
        }
        result += dp[0][N-1];
    }
    cin.close();
    cout << result << endl;
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

/* int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int Q;
    cin >> Q;
    int result = 0;
    while (Q-- > 0)
    {
        int L, N;
        cin >> L >> N;
        vector<int> pos;
        pos.push_back(0);
        for (int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            pos.push_back(temp);
        }
        pos.push_back(L);
        N += 2;

        vector<vector<int>> dp(N, vector<int>(N, 1e6));
        for (int i = 0; i < N; i++) 
            dp[i][i] = 0;
        for (int i = 0; i < N-1; i++)
            dp[i][i+1] = 0;
        for (int w = 2; w < N; w++)
        {
            for (int i = 0; i < N - w; i++) {
                int j = i + w;
                int min_val = 1e6;
                for (int k = i+1; k < j; k++) {
                    min_val = min(min_val, dp[i][k] + dp[k][j]);
                }
                dp[i][j] = min(dp[i][j], (pos[j] - pos[i]) + min_val);
            }
        }
        result += dp[0][N-1];
    }
    cout << result << endl;
}
 */