#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(const char* filename) {
    ifstream cin(filename);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin.close();

    int max = -INFINITY;
    int s = 0;
    for (int y = 0; y < n; y++) {
        s += arr[y];
        max = __max(s, max); // new record update
        if (s < 0) {
            s = 0; // reset if negative
        }
    }
    cout << max << "\n";
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
