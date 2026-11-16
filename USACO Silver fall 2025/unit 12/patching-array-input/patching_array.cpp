#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(const char* filename) {
    ifstream cin(filename);
    vector<int> nums;
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        int num;
        cin>>num;
        nums.push_back(num);
    }
    cin.close();
    
    sort(nums.begin(), nums.end());
    ll miss = 1;
    int patches = 0;
    int i = 0;

    while (miss <= m) {
        if (i < nums.size() && nums[i] <= miss) {
            miss += nums[i];
            i++;
        } else {
            // patch with 'miss'
            // prev bound [1, miss-1], and now you have [miss+1, 2*miss-1] and miss
            // so new bound is [1, 2*miss-1] which means new miss is miss*2 exactly
            // i does not change, you still need to evaluate current num to see if it is in bounds
            miss *= 2;
            patches++;
        }
    }
    cout << patches << endl;
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