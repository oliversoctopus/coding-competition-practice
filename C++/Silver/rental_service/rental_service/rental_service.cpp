// rental_service.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Make a psum for store, rent, and cow gallons
// Then test out how many cows to rent, use psums to find money made, and take max value
// My previous solution: 106 ms, 1 wrong answer, 1 error
// My current solution: 294 ms, zero wrong
// Internal sol: 102 ms, zero wrong

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
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end(), greater<int>());

    // {price per gallon, max gallons}
    vector<pair<int, int>> stores(m);
    for (int i = 0; i < m; i++) {
        int q, p;
        cin >> q >> p;
        stores[i].first = p;
        stores[i].second = q;
    }
    sort(stores.begin(), stores.end(), greater<pair<int, int>>());

    vector<int> rents(r);
    for (int i = 0; i < r; i++) {
        cin >> rents[i];
    }
    sort(rents.begin(), rents.end(), greater<int>());

    int shop_at = 0;
    int rent_at = 0;
    ll ans = 0;
    while (cows.size() > 0) {
        int amnt = cows[0];
        int rent_price = 0;
        if (rent_at < r) {
            rent_price = rents[rent_at];
        }
        int shop_total = 0;
        int cur_shop_at = shop_at;
        while (amnt > 0 && cur_shop_at < m) {
            auto cur_store = stores[cur_shop_at];
            if (cur_store.second > amnt) {
                shop_total += amnt * cur_store.first;
                if (shop_total > rent_price || rent_at >= r) {
                    stores[cur_shop_at].second -= amnt;
                }
                amnt = 0;
            }
            else {
                shop_total += cur_store.second * cur_store.first;
                amnt -= cur_store.second;
                cur_shop_at++;
            }
        }
        if (shop_total > rent_price || rent_at >= r) {
            ans += shop_total;
            shop_at = cur_shop_at;
            cows.erase(cows.begin());
        }
        else if (rent_price >= shop_total || shop_at >= m) {
            ans += rent_price;
            rent_at++;
            cows.pop_back();
        }
        else {
            throw runtime_error("Failed");
        }
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
