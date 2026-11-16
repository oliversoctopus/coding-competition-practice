#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
x-y >= V1
x+y <= V2
for one mountain to be in another


running minimum x-y from the end to the beginning
for each mountain: if x-y is more than running minimum
then we know:
1. It's contained on one side b/c it has less x+y
2. It's contained on the other side b/c it has more x-y
*/
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) {
        return true;
    } else if (a.first > b.first) {
        return false;
    } else {
        if (a.second > b.second) {
            return true;
        } else {
            return false;
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int n;
    cin>>n;
    vector<pair<int,int>> mountains(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin>>x>>y;
        mountains[i] = {x, y};
    }
    vector<pair<int,int>> rotated(n);
    for (int i = 0; i < n; i++) {
        rotated[i] = {mountains[i].first+mountains[i].second, mountains[i].first-mountains[i].second};
    }
    
    sort(rotated.begin(), rotated.end(), compare);
    /* for (auto m : rotated) {
        cout << m.first << " " << m.second << "\n";
    } */

    int min_xmy = 2e9+1;
    int seen = n;
    for (int i = n-1; i >= 0; i--) {
        pair<int,int> mountain = rotated[i];
        if (mountain.second >= min_xmy) {
            seen--;
        }
        min_xmy = min(min_xmy, mountain.second);
    }
    cout << seen << "\n";
}
