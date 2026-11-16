// lifeguards.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Internal Sol slowest time: 69 ms
// My solution slowest time: 163 ms

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
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int n;
    cin >> n;

    // {coordinate, lifeguard #, start or stop (1 is start, -1 is stop)}
    vector<vector<int>> points;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;

        points.push_back({ start, i, 1 });
        points.push_back({ end, i, -1 });
    }

    sort(points.begin(), points.end());
    set<int> working = {};
    vector<int> lost_time(n);
    int total_time = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        vector<int> start = points[i];
        vector<int> end = points[i + 1];
        int length = end[0] - start[0];
        if (start[2] == 1) {
            working.insert(start[1]);
        }
        else {
            working.erase(start[1]);
        }
        if (working.size() == 0) {
            continue;
        }
        if (working.size() == 1) {
            lost_time[*working.begin()] += length;
        }
        total_time += length;
    }

    int ans = total_time - *min_element(lost_time.begin(), lost_time.end());
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
