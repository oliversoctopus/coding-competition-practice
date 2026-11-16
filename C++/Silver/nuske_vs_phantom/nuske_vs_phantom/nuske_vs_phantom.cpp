// nuske_vs_phantom.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> grid(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char a;
            cin >> a;
            grid[i][j] = (a == '1');
        }
    }

    vector<vector<int>> pref(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            if (grid[i][j] == 1) {
                if (grid[i - 1][j] && grid[i][j - 1]) {
                    pref[i][j]--;
                }
                else if (!grid[i - 1][j] && !grid[i][j - 1]) {
                    pref[i][j]++;
                }
            }
        }
    }

    vector<vector<int>> horizontal(n + 1, vector<int>(m + 1));
    vector<vector<int>> vertical(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            horizontal[i][j] = horizontal[i][j - 1];
            vertical[i][j] = vertical[i - 1][j];
            if (grid[i][j]) {
                horizontal[i][j] += !grid[i][j - 1];
                vertical[i][j] += !grid[i - 1][j];
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = grid[x1][y1];
        ans += horizontal[x1][y2] - horizontal[x1][y1];
        ans += vertical[x2][y1] - vertical[x1][y1];
        ans += pref[x2][y2] - pref[x1][y2] - pref[x2][y1] + pref[x1][y1];
        cout << ans << "\n";
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
