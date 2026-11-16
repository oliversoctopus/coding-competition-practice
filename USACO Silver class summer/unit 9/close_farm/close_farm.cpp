#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int, vector<int>> adj;
map<int, bool> visited;

map<int, bool> traverse(int key) {
    vector<int> nodes = adj[key];
    visited[key] = true;
    for (int n : nodes) {
        if (visited[n]) {
            continue;
        }
        //cout << key << " " << n << endl;
        visited = traverse(n);
    }
    return visited;
}

int main() {
    ifstream cin("closing.in");
    ofstream cout("closing.out");
    int n, m;
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        int rm;
        cin >> rm;
        visited.clear();
        int start_key;
        for (const auto& pair : adj) {
            visited[pair.first] = false;
            start_key = pair.first;
        }
        visited = traverse(start_key);
        bool success = true;
        for (const auto& pair : visited) {
            if (pair.second == false) {
                cout << "NO" << "\n";
                success = false;
                break;
            }
        }
        if (success) { cout << "YES" << "\n"; }

        adj.erase(rm);
        for (const auto& pair : adj) {
            vector<int> cur_nodes;
            for (int i = 0; i < pair.second.size(); i++) {
                if (pair.second[i] != rm) {
                    cur_nodes.push_back(pair.second[i]);
                }
            }
            adj[pair.first] = cur_nodes;
        }
    }
    cin.close();
    cout.close();
}
