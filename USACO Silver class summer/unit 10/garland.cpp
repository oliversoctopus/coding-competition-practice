#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    string garland;
    cin>>garland;
    int q;
    cin>>q;
    int result = 0;
    for (int _ = 0; _ < q; _++) {
        int changes;
        char color;
        cin>>changes>>color;
        int mx = -1;
        int y = -1;
        int cur_changes = 0;
        for (int x = 0; x < n; x++) {
            while (cur_changes <= changes && y < n - 1) {
                y++;
                cur_changes += (garland[y] != color);
            }
            if (cur_changes > changes) {
                y--;
                cur_changes = changes;
            }
            mx = max(mx, y - x + 1);
            cur_changes -= (garland[x] != color);
        }
        //cout << "Sub-result: " << mx << endl;
        result += mx;
    }
    cout << result << endl;
}
