// splitting_the_field.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

ll calc_area(vector<int> extrema) {
    return (ll) (extrema[2] - extrema[0]) * (ll) (extrema[3] - extrema[1]);
}

int main()
{
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);

    int n;
    cin >> n;

    // {min_x, min_y, max_x, max_y}
    vector<int> extrema(4, -1);
    vector<pair<int, int>> cows_x(n);
    vector<pair<int, int>> cows_y(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cows_x[i] = { x,y };
        cows_y[i] = { x,y };
        if (extrema[0] == -1) {
            extrema[0] = x;
            extrema[2] = x;
            extrema[1] = y;
            extrema[3] = y;
        }
        else {
            extrema[0] = min(extrema[0], x);
            extrema[1] = min(extrema[1], y);
            extrema[2] = max(extrema[2], x);
            extrema[3] = max(extrema[3], y);
        }
    }

    ll one_area = calc_area(extrema);
    sort(cows_x.begin(), cows_x.end());
    auto cmp = [&](const pair<int, int>& c1, const pair<int, int>& c2) {
        return c1.second < c2.second;
        };
    sort(cows_y.begin(), cows_y.end(), cmp);

    vector<vector<int>> left(n, vector<int>(4, -1));
    vector<vector<int>> right(n, vector<int>(4, -1));
    vector<vector<int>> up(n, vector<int>(4, -1));
    vector<vector<int>> down(n, vector<int>(4, -1));
    for (int i = 0; i < n; i++) {
        auto left_cow = cows_x[i];
        auto down_cow = cows_y[i];
        left[i][0] = left_cow.first;
        left[i][2] = left_cow.first;
        left[i][1] = left_cow.second;
        left[i][3] = left_cow.second;
        down[i][0] = down_cow.first;
        down[i][2] = down_cow.first;
        down[i][1] = down_cow.second;
        down[i][3] = down_cow.second;
        if (i > 0) {
            left[i][0] = min(left[i][0], left[i - 1][0]);
            left[i][1] = min(left[i][1], left[i - 1][1]);
            left[i][2] = max(left[i][2], left[i - 1][2]);
            left[i][3] = max(left[i][3], left[i - 1][3]);
            down[i][0] = min(down[i][0], down[i - 1][0]);
            down[i][1] = min(down[i][1], down[i - 1][1]);
            down[i][2] = max(down[i][2], down[i - 1][2]);
            down[i][3] = max(down[i][3], down[i - 1][3]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        auto right_cow = cows_x[i];
        auto up_cow = cows_y[i];
        right[i][0] = right_cow.first;
        right[i][2] = right_cow.first;
        right[i][1] = right_cow.second;
        right[i][3] = right_cow.second;
        up[i][0] = up_cow.first;
        up[i][2] = up_cow.first;
        up[i][1] = up_cow.second;
        up[i][3] = up_cow.second;
        if (i < n - 1) {
            right[i][0] = min(right[i][0], right[i + 1][0]);
            right[i][1] = min(right[i][1], right[i + 1][1]);
            right[i][2] = max(right[i][2], right[i + 1][2]);
            right[i][3] = max(right[i][3], right[i + 1][3]);
            up[i][0] = min(up[i][0], up[i + 1][0]);
            up[i][1] = min(up[i][1], up[i + 1][1]);
            up[i][2] = max(up[i][2], up[i + 1][2]);
            up[i][3] = max(up[i][3], up[i + 1][3]);
        }
    }

    ll min_area = -1;
    for (int i = 0; i < n - 1; i++) {
        ll cur_area = calc_area(left[i]) + calc_area(right[i + 1]);
        if (min_area == -1) {
            min_area = cur_area;
        }
        else {
            min_area = min(min_area, cur_area);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        ll cur_area = calc_area(down[i]) + calc_area(up[i + 1]);
        if (min_area == -1) {
            min_area = cur_area;
        }
        else {
            min_area = min(min_area, cur_area);
        }
    }

    cout << one_area - min_area << "\n";
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
