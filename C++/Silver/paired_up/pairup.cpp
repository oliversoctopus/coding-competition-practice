#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int N;
    cin>>N;
    vector<vector<int>> cows;
    for (int i = 0; i < N; i++) {
        vector<int> temp(2);
        cin>>temp[1]>>temp[0]; // {output, # cows}
        cows.push_back(temp);
    }
    sort(cows.begin(), cows.end());
    int left = 0;
    int right = N-1;
    int max_val = 0;
    int l_num = cows[left][1];
    int r_num = cows[right][1];
    while (left <= right) {
        int cur_sum = cows[left][0] + cows[right][0];
        max_val = max(cur_sum, max_val);
        if (l_num == r_num) {
            left++;
            right--;
            if (left >= N || right < 0) break;
            l_num = cows[left][1];
            r_num = cows[right][1];
        } else if (l_num > r_num) {
            l_num -= r_num;
            right--;
            if (left >= N || right < 0) break;
            r_num = cows[right][1];
        } else if (l_num < r_num) {
            r_num -= l_num;
            left++;
            if (left >= N || right < 0) break;
            l_num = cows[left][1];
        }
    }
    cout << max_val << "\n";
}
