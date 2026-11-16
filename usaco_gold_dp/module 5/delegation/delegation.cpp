#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool works(int k, int n, const vector<vector<int>>& adj) {
    vector<int> dp(n); // dp[i] = path length up to node i
    vector<int> parent(n);
    parent[0] = -1;
    vector<pair<int,int>> process; // {node index, has_been_processed_for_children}
    process.push_back({0, 0});
    while (process.size() > 0) {
        pair<int, int> cur = process.back();
        process.pop_back();
        if (cur.second == 0) {
            cur.second = 1;
            process.push_back(cur);
            for (int child : adj[cur.first]) {
                if (child != parent[cur.first]) {
                    process.push_back({child, 0});
                    parent[child] = cur.first;
                }
            }
        } else {
            int node = cur.first;
            // get path lengths of children, add 1 (parent-child connection)
            map<int, int> path_counts;
            map<int, bool> checked;
            int n_children = 0;
            for (int child : adj[node]) {
                if (child != parent[node]) {
                    n_children++;
                    int cur_path = dp[child]+1;
                    if (cur_path > k) cur_path -= k;
                    path_counts[cur_path]++;
                    checked[cur_path] = false;
                }
            }
            // find mismatches
            int mismatches = 0;
            int mismatch_n = 0;
            for (auto& [key, value] : path_counts) {
                if (key == k) {
                    n_children -= value;
                    continue;
                }
                if (checked[key]) continue;
                checked[key] = true;
                checked[k - key] = true;
                int temp = value;
                int other = path_counts[k - key];
                if (k - key == key) {
                    temp = value / 2;
                    other = (value+1) / 2;
                }
                if (abs(other-temp) > 1) return false;
                if (abs(other-temp) == 1) {
                    if (mismatches > 0) return false;
                    mismatches++;
                    if (other > temp) {
                        mismatch_n = k - key;
                    } else {
                        mismatch_n = key;
                    }
                }
            }
            // handle mismatches
            if (n_children % 2 == 0 && mismatches > 0) {
                /* for (auto& [key, value] : path_counts) {
                    cout << key << " " << value << "\n";
                }
                cout << node << " " << n_children << " " << mismatches << " " << mismatch_n << "\n"; */
                return false;
            }
            if (n_children % 2 == 0) {
                dp[node] = 0;
            } else {
                dp[node] = mismatch_n;
            }
        }
    }
    if (dp[0] != 0 && dp[0] != k) return false;
    return true;
}

int main() {
    freopen("2.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    cout << n << "\n";
    if (n == 1) return 0;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    int edges = n - 1;

    vector<int> possible;
    for (int i = 1; i < n; i++) {
        if (edges % i == 0) possible.push_back(i);
    }
    /* for (int i = 0; i < possible.size(); i++) {
        cout << possible[i] << " ";
    }
    cout << "\n"; */

    int low = 0;
    int high = possible.size()-1;
    while (low < high) {
        //cout << low << " " << high << flush << "\n";
        int mid = (low+high+1) / 2;
        if (works(possible[mid], n, adj)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    int last_possible = possible[low];

    for (int i = 1; i < n; i++) {
        if (i > last_possible) cout << "0";
        else {
            if (edges % i == 0) cout << "1";
            else cout << "0";
        }
    }
    cout << "\n";
}