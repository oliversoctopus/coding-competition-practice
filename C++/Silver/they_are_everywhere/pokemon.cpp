#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    cin>>N;
    string s;
    cin>>s;
    map<char, int> types;
    int i = 0;
    for (char c : s) {
        if (types.count(c) == 0) {
            types[c] = i;
            i++;
        }
    }
    int M = i; // number of distinct types
    vector<int> p;
    for (char c : s) {
        p.push_back(types[c]);
    }
    
    int ans = 1e6;
    int left = 0;
    int right = 0;
    map<int, int> caught;
    while (left < N) {
        while (right < N && caught.size() < M) {
            caught[p[right]]++;
            right++;
        }
        if (right == N && caught.size() < M) break;
        ans = min(ans, right - left);
        int removed = p[left];
        if (caught[removed] == 1) caught.erase(removed);
        else caught[removed]--;
        left++;
    }
    cout << ans << "\n";
}