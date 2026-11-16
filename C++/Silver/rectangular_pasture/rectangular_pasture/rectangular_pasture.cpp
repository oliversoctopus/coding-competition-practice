// rectangular_pasture.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int main()
{
    int n;
    cin >> n;

    set<int> seen_x, seen_y;
    vector<pair<int, int>> cows(n);
    for (auto &c : cows) {
        cin >> c.first >> c.second;
        seen_x.insert(c.first);
        seen_y.insert(c.second);
    }

    sort(cows.begin(), cows.end());
    for (int i = 0; i < n; i++) {
        cows[i].first = i;
    }

    auto cmp = [&](const pair<int, int>& c1, const pair<int, int>& c2) {
        return c1.second < c2.second;
        };
    sort(cows.begin(), cows.end(), cmp);
    for (int i = 0; i < n; i++) {
        cows[i].second = i;
    }

    sort(cows.begin(), cows.end());
    vector<vector<int>> above(n, vector<int>(n+1));
    vector<vector<int>> below(n, vector<int>(n+1));
    for (int i = 0; i < n; i++) {
        int cur_y = cows[i].second;
        for (int x = 1; x <= n; x++) {
            below[cur_y][x] = (below[cur_y][x - 1] + (cows[x - 1].second < cur_y));
            above[cur_y][x] = (above[cur_y][x - 1] + (cows[x - 1].second > cur_y));
        }
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pair<int, int> c1 = cows[i];
            pair<int, int> c2 = cows[j];
            int bottom = min(c1.second, c2.second);
            int top = max(c1.second, c2.second);

            int below_n = 1 + below[bottom][c2.first + 1] - below[bottom][c1.first];
            int above_n = 1 + above[top][c2.first + 1] - above[top][c1.first];

            ans += below_n * above_n;
        }
    }

    ans += n + 1;
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
