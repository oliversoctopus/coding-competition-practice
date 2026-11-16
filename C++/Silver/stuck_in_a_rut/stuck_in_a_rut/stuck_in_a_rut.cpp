// stuck_in_a_rut.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    int n;
    cin >> n;
    // {x, y, cow#}
    vector<vector<int>> east;
    vector<vector<int>> north;

    for (int i = 0; i < n; i++) {
        char dir;
        int x, y;
        cin >> dir >> x >> y;
        if (dir == 'E') {
            east.push_back({ x,y,i });
        }
        else {
            north.push_back({ x,y,i });
        }
    }

    auto cmp = [&](const vector<int>& c1, const vector<int>& c2) {
        return c1[1] < c2[1];
        };
    sort(east.begin(), east.end(), cmp);
    sort(north.begin(), north.end());

    vector<bool> stopped(n, false);
    vector<int> blame(n, 0);
    for (int i = 0; i < east.size(); i++) {
        for (int j = 0; j < north.size(); j++) {
            auto cur_n = north[j];
            auto cur_e = east[i];
            if (!stopped[cur_e[2]] && !stopped[cur_n[2]] && cur_n[0] > cur_e[0] && cur_e[1] > cur_n[1]) {
                // intersection a, y
                int n_dist = cur_e[1] - cur_n[1];
                int e_dist = cur_n[0] - cur_e[0];
                if (e_dist < n_dist) {
                    stopped[cur_n[2]] = true;
                    blame[cur_e[2]] += blame[cur_n[2]] + 1;
                }
                else if (n_dist < e_dist) {
                    stopped[cur_e[2]] = true;
                    blame[cur_n[2]] += blame[cur_e[2]] + 1;
                }
            }
        }
    }

    for (int c : blame) {
        cout << c << "\n";
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
