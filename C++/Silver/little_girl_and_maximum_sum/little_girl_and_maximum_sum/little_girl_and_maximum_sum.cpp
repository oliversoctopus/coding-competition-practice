// little_girl_and_maximum_sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    int n, q;
    cin >> n >> q;
    vector<ll> arr;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        arr.push_back(elem);
    }

    vector<ll> diff(n + 1);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        diff[l - 1]++;
        diff[r]--;
    }

    vector<ll> psum(n);
    for (int i = 0; i < n; i++) {
        psum[i] = diff[i];
        if (i != 0) psum[i] += psum[i - 1];
    }

    sort(psum.begin(), psum.end());
    sort(arr.begin(), arr.end());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += psum[i] * arr[i];
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
