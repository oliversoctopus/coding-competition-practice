#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> visited;
vector<vector<int>> adj_matrix;
int n;

void make_adj_mat(vector<vector<int>> cows, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x1 = cows[i][0];
            int y1 = cows[i][1];
            int x2 = cows[j][0];
            int y2 = cows[j][1];
            int p = cows[i][2];
            if (pow(pow(x2-x1, 2) + pow(y2-y1, 2), 0.5) <= p) {
                adj_matrix[i].push_back(1);
            } else {
                adj_matrix[i].push_back(0);
            }
        }
    }
}

int find_num(int c) {
    visited[c] = 1;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (i == c || visited[i] == 1) {
            continue;
        }
        if (adj_matrix[c][i] == 1) {
            ans += find_num(i);
        }
    }
    return ans;
}

int main() {
    ifstream cin("moocast.in");
    cin >> n;
    visited = vector<int>(n);
    adj_matrix = vector<vector<int>>(n);

    vector<vector<int>> cows(n);
    for (int i = 0; i < n; i++) {
        int x, y, p;
        cin >> x >> y >> p;
        cows[i] = {x, y, p};
    }
    cin.close();
    make_adj_mat(cows, n);

    int res = 1;
    for (int i = 0; i < n; i++) {
        res = max(res, find_num(i));
    }
    ofstream cout("moocast.out");
    cout << res;
    cout.close();
}
