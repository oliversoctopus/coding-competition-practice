#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int n;
    cin>>n;

    map<vector<int>, int> visited;

    int x = 0;
    int y = 0;
    int t = 0;
    visited[{0, 0}] = 0;
    int min_diff = INT32_MAX;
    for (int i = 0; i < n; i++) {
        char dir;
        cin>>dir;
        int len;
        cin>>len;
        int dx = 0;
        int dy = 0;
        if (dir == 'N') {
            dy = 1;
        } else if (dir == 'S') {
            dy = -1;
        } else if (dir == 'E') {
            dx = 1;
        } else if (dir == 'W') {
            dx = -1;
        } else {
            cout << "Impossible result\n";
        }
        for (int j = 0; j < len; j++) {
            t++;
            x += dx;
            y += dy;
            if (visited.find({x, y}) != visited.end()) {
                // it exists already
                if (t - visited[{x, y}] < min_diff) {
                    min_diff = t - visited[{x, y}];
                }
            }
            visited[{x, y}] = t;
        }
    }
    if (min_diff == INT32_MAX) {
        min_diff = -1;
    }
    cout << min_diff << "\n";
}
