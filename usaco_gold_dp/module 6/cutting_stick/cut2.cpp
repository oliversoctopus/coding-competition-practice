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

vector<vector<int>> dp;
vector<int> pos;

int cost(int start, int end) {
    if (end - start <= 1) return 0;
    if (dp[start][end] != 1e6) return dp[start][end];
    int min_val = 1e6;
    for (int k = start+1; k < end; k++) {
        min_val = min(min_val, cost(start, k) + cost(k, end));
    }
    dp[start][end] = min(dp[start][end], (pos[end] - pos[start]) + min_val);
    return dp[start][end];
} 

void solve(const char* filename) {
    ifstream cin(filename);
    int Q;
    cin >> Q;
    int result = 0;
    while (Q-- > 0)
    {
        int L, N;
        cin >> L >> N;
        pos = vector<int>(1); // initial 0
        for (int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            pos.push_back(temp);
        }
        pos.push_back(L);
        N += 2;
        dp = vector<vector<int>>(N, vector<int>(N, 1e6));
        result += cost(0, N-1);
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