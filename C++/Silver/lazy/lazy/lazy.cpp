// lazy.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    int width = 2 * n - 1;
    int mid = n - 1;
    vector<vector<int>> rotated(width, vector<int>(width));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            int amnt = i + j + 1;
            rotated[i + j][mid + j * 2 - amnt + 1] = a;
        }
    }

    vector<vector<int>> psum(width + 1, vector<int>(width + 1));
    int area_width = 2 * k - 1;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            psum[i][j] = rotated[i][j];
            if (i > 0) psum[i][j] += psum[i - 1][j];
            if (j > 0) psum[i][j] += psum[i][j - 1];
            if (i > 0 && j > 0) psum[i][j] -= psum[i - 1][j - 1];
        }
    }

    int max_total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int amnt = i + j + 1;
            int a = i + j;
            int b = mid + j * 2 - amnt + 1;
            int x1 = max(a - k, 0);
            int y1 = max(b - k, 0);
            int x2 = min(a + k, width - 1);
            int y2 = min(b + k, width - 1);
            int total = psum[x2][y2];
            if (x1 - 1 > 0) total -= psum[x1 - 1][y2];
            if (y1 - 1 > 0) total -= psum[x2][y1 - 1];
            if (x1 - 1 > 0 && y1 - 1 > 0) total += psum[x1 - 1][y1 - 1];
            max_total = max(max_total, total);
        }
    }

    cout << max_total << "\n";
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
