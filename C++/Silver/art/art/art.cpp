// art.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    int n;
    cin >> n;

    // {min_row, min_col, max_row, max_col}
    map<int, vector<int>> bounds;
    vector<vector<int>> canvas(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (!bounds.count(val)) {
                bounds[val] = { i, j, i, j };
            }
            bounds[val][0] = min(bounds[val][0], i);
            bounds[val][1] = min(bounds[val][1], j);
            bounds[val][2] = max(bounds[val][2], i);
            bounds[val][3] = max(bounds[val][3], j);

            canvas[i][j] = val; 
        }
    }

    bounds.erase(0);

    if (bounds.size() != 1) {
        vector<vector<int>> pref(n + 1, vector<int>(n + 1));
            for (const auto &imap : bounds) {
                vector<int> bound = imap.second;
                int a = bound[0];
                int b = bound[1];
                int c = bound[2];
                int d = bound[3];
                pref[a][b]++;
                pref[a][d + 1]--;
                pref[c + 1][b]--;
                pref[c + 1][d + 1]++;
            }

            set<int> colors;
            for (int i = 1; i <= n * n; i++) {
                colors.insert(i);
            }

            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    if (r > 0) { pref[r][c] += pref[r - 1][c]; }
                    if (c > 0) { pref[r][c] += pref[r][c - 1]; }
                    if (r > 0 && c > 0) { pref[r][c] -= pref[r - 1][c - 1]; }
                    if (pref[r][c] > 1) { colors.erase(canvas[r][c]); }
                }
            }

            cout << colors.size() << "\n";
    }
    else {
        cout << n * n - 1 << "\n";
    }
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
