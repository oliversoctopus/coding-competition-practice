// leaping_tak.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> s(k);

    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        s[i] = { l,r };
    }

    vector<ll> sum(n + 1);
    sum[1] = 1;
    for (int i = 2; i <= n; i++) {
        ll cur = 0;
        for (int j = 0; j < k; j++) {
            if (s[j].first >= i) continue;
            int l = max(1, i - s[j].second);
            int r = i - s[j].first;
            cur += sum[r] - sum[l - 1];
        }
        cur %= 998244353;
        if (cur < 0) {
            cur += 998244353;
        }
        sum[i] = (sum[i - 1] + cur) % 998244353;
    }
    ll ans = sum[n] - sum[n - 1];
    if (ans < 0) {
        ans += 998244353;
    }
    cout << ans << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
