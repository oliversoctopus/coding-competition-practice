#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int range(vector<int> arr, int i, int j) {
    int max_v=-1e9-1;
    int min_v=1e9+1;
    for (int k = i; k <= j; k++) {
        max_v = max(arr[k], max_v);
        min_v = min(arr[k], min_v);
    }
    return max_v - min_v;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<vector<int>> ranges(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> ranges[i][j];
            //cout << i << " " << j << "\n";
        }
    }
    /* for (auto range : ranges) {
        for (int r : range) {
            cout << r << " ";
        }
        cout << "\n";
    } */
    vector<int> arr(n);
    arr[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        int diff = ranges[i][i+1];
        arr[i] = arr[i+1] + diff;
        bool success = true;
        for (int j = i+2; j < n; j++) {
            if (range(arr, i, j) != ranges[i][j]) {
                success = false;
                break;
            }
        }
        if (!success)
            arr[i] = arr[i+1] - diff;
    }
    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i];
        if (i == arr.size()-1) {
            cout << num;
        } else {
            cout << num << " ";
        }
    }
    cout<<"\n";
}