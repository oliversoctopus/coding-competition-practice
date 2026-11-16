#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int N, K;
    cin>>N>>K;
    vector<int> d(N);
    for (int i = 0; i < N; i++) {
        cin>>d[i];
    }
    sort(d.begin(), d.end());

    // precompute all best sets with left index = i
    vector<vector<int>> best(N, vector<int>(2));
    int left = 0;
    int right = 0;
    while (left < N) {
        while (right < N && d[right] - d[left] <= K) right++;
        vector<int> temp = {left, right};
        best[left] = temp;
        left++;
    }
    // suffix max: best set with left index >= i, tiebroken by greater left index
    vector<vector<int>> best_smax(N+1, vector<int>(2));
    best_smax[N] = {N, N};
    best_smax[N-1] = best[N-1];
    for (int i = N-2; i >= 0; i--) {
        if (best[i][1]-best[i][0] > best_smax[i+1][1]-best_smax[i+1][0]) {
            best_smax[i] = best[i];
        } else {
            best_smax[i] = best_smax[i+1];
        }
    }

    // double 2 pointer
    int result = 0;
    for (int l1 = 0; l1 < N; l1++) {
        int r1 = best[l1][1];
        vector<int> temp = best_smax[r1];
        int l2 = temp[0];
        int r2 = temp[1];
        result = max(result, (r1-l1) + (r2-l2));
    }
    cout << result << "\n";
}
