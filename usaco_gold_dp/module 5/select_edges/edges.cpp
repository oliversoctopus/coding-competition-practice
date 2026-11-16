#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(const char* filename) {
    ifstream cin(filename);
    int n;
    cin>>n;
    vector<int> d(n); // restrictions
    for (int i = 0; i < n; i++) {
        cin>>d[i];
    }
    map<int, map<int, ll>> adj; // adj[i][j] = weight
    for (int i = 0; i < n-1; i++) {
        int n1, n2, w;
        cin>>n1>>n2>>w;
        adj[n1-1][n2-1] = w;
        adj[n2-1][n1-1] = w;
    }
    cin.close();

    vector<ll> dp1(n, -1); // value of subtree i, if you don't care about parent node
    vector<ll> dp2(n, -1); // value of subtree i, if you do care about parent node (restriction-1)
    vector<int> parent(n); // parent of node i, -1 if node i is the root
    parent[0] = -1;
    vector<int> node_stack;
    node_stack.push_back(0);
    while (node_stack.size() > 0) {
        int cur = node_stack.back();
        // find children
        vector<int> children;
        for (auto&[key, value] : adj[cur]) {
            if (key != parent[cur]) {
                children.push_back(key);
                parent[key] = cur;
            }
        }
        // check if children are processed
        bool processed = true;
        for (int key : children) {
            if (parent[cur] != key && dp1[key] == -1) {
                processed = false;
                break;
            }
        }
        if (processed == false) {
            // add all children
            for (int key : children) {
                if (parent[cur] != key) {
                    node_stack.push_back(key);
                    parent[key] = cur;
                }
            }
        } else {
            // process node's value
            node_stack.pop_back(); // remove node when actually processing it
            ll s = 0;
            for (int c : children) {
                s += dp1[c];
            }
            // get all the edge gain values
            vector<ll> edge_vals;
            for (int c : children) {
                ll adj_value = adj[cur][c] + dp2[c] - dp1[c];
                edge_vals.push_back(adj_value);
            }
            sort(edge_vals.begin(), edge_vals.end());
            ll dp2_sum = s;
            ll dp1_sum = s;
            int dp1_limit = min((int)edge_vals.size(), d[cur]); // account for restriction
            int dp2_limit = min((int)edge_vals.size(), d[cur]-1); // account for restriction plus parent connection
            for (int i = 0; i < dp1_limit; i++) {
                int ind = edge_vals.size() - i - 1;
                if (edge_vals[ind] <= 0) {
                    // not worth taking any more edges, they're all negative
                    break;
                }
                if (i < dp2_limit) dp2_sum += edge_vals[ind];
                dp1_sum += edge_vals[ind];
            }
            if (d[cur] == 0) dp2_sum = -1e12;
            dp1[cur] = dp1_sum;
            dp2[cur] = dp2_sum;
        }
    }
    cout << dp1[0] << "\n";
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

/* int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<int> d(n); // restrictions
    for (int i = 0; i < n; i++) {
        cin>>d[i];
    }
    map<int, map<int, ll>> adj; // adj[i][j] = weight
    for (int i = 0; i < n-1; i++) {
        int n1, n2, w;
        cin>>n1>>n2>>w;
        adj[n1-1][n2-1] = w;
        adj[n2-1][n1-1] = w;
    }

    vector<ll> dp1(n, -1); // value of subtree i, if you don't care about parent node
    vector<ll> dp2(n, -1); // value of subtree i, if you do care about parent node (restriction-1)
    vector<int> parent(n); // parent of node i, -1 if node i is the root
    parent[0] = -1;
    vector<int> node_stack;
    node_stack.push_back(0);
    while (node_stack.size() > 0) {
        int cur = node_stack.back();
        // find children
        vector<int> children;
        for (auto&[key, value] : adj[cur]) {
            if (key != parent[cur]) {
                children.push_back(key);
                parent[key] = cur;
            }
        }
        // check if children are processed
        bool processed = true;
        for (int key : children) {
            if (parent[cur] != key && dp1[key] == -1) {
                processed = false;
                break;
            }
        }
        if (processed == false) {
            // add all children
            for (int key : children) {
                if (parent[cur] != key) {
                    node_stack.push_back(key);
                    parent[key] = cur;
                }
            }
        } else {
            // process node's value
            node_stack.pop_back(); // remove node when actually processing it
            ll s = 0;
            for (int c : children) {
                s += dp1[c];
            }
            // get all the edge gain values
            vector<ll> edge_vals;
            for (int c : children) {
                ll adj_value = adj[cur][c] + dp2[c] - dp1[c];
                edge_vals.push_back(adj_value);
            }
            sort(edge_vals.begin(), edge_vals.end());
            ll dp2_sum = s;
            ll dp1_sum = s;
            int dp1_limit = min((int)edge_vals.size(), d[cur]); // account for restriction
            int dp2_limit = min((int)edge_vals.size(), d[cur]-1); // account for restriction plus parent connection
            for (int i = 0; i < dp1_limit; i++) {
                int ind = edge_vals.size() - i - 1;
                if (edge_vals[ind] <= 0) {
                    // not worth taking any more edges, they're all negative
                    break;
                }
                if (i < dp2_limit) dp2_sum += edge_vals[ind];
                dp1_sum += edge_vals[ind];
            }
            if (d[cur] == 0) dp2_sum = -1e12;
            dp1[cur] = dp1_sum;
            dp2[cur] = dp2_sum;
        }
    }
    cout << dp1[0] << "\n";
} */
