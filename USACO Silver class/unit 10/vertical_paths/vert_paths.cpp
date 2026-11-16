#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> leaf(n, 1);
    vector<int> parents(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        val--;
        leaf[val] = 0;
        parents[i] = val;
    }

    vector<int> leaves;
    for (int i = 0; i < n; i++) {
        if (leaf[i] == 1) {
            leaves.push_back(i);
        }
    }

    vector<int> taken(n);
    vector<vector<int>> paths;
    for (int leaf_ind : leaves) {
        vector<int> cur_path;
        cur_path.push_back(leaf_ind + 1);
        int cur_elem = parents[leaf_ind];
        while (!taken[cur_elem]) {
            taken[cur_elem] = 1;
            cur_path.push_back(cur_elem + 1);
        }
        reverse(cur_path.begin(), cur_path.end());
        paths.push_back(cur_path);
    }
    
    cout << paths.size() << "\n";
    for (auto path : paths) {
        cout << path.size() << " ";
        for (int p : path) {
            cout << p << " ";
        }
        cout << "\n";
    }
}
