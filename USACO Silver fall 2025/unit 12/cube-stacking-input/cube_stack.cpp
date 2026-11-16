#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(const char* filename) {
    ifstream cin(filename);
    ll n;
    cin>>n;
    cin.close();

    // cube stack upper bound is ~third root(6n)
    // 1<=n<=1e9 so bounds are 1 to 1817
    // condition: x(x+1)(x+2) >= 6n
    int low = 1; 
    int high = 2000;
    while (low < high) {
        int mid = (low + high) / 2;
        ll cubes = (ll)mid * (mid + 1) * (mid + 2);
        if (cubes >= 6 * n) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    //cout << low << "\n";

    int remove = 0;
    ll boxes = (ll)low * (low+1) * (low+2) / 6;
    for (int r = low; r >= 1; r--) {
        if (boxes - r < n) break;
        boxes -= r;
        remove++;
    }
    //cout << remove << "\n";

    int touch_floor = low * (low+1) / 2 - remove;
    cout << touch_floor << "\n";
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

/*int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin>>n;
    // cube stack upper bound is ~third root(6n)
    // 1<=n<=1e9 so bounds are 1 to 1817
    // condition: x(x+1)(x+2) >= 6n
    int low = 1; 
    int high = 2000;
    while (low < high) {
        int mid = (low + high) / 2;
        ll cubes = (ll)mid * (mid + 1) * (mid + 2);
        if (cubes >= 6 * n) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    //cout << low << "\n";

    int remove = 0;
    ll boxes = (ll)low * (low+1) * (low+2) / 6;
    for (int r = low; r >= 1; r--) {
        if (boxes - r < n) break;
        boxes -= r;
        remove++;
    }
    //cout << remove << "\n";

    int touch_floor = low * (low+1) / 2 - remove;
    cout << touch_floor << "\n";
}*/