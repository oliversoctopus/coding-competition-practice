// mountain.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

struct Mountain {
    int x;
    int y;

    bool operator<(const Mountain& b) { return y - x > b.y - b.x; }
};

int main()
{
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int n;
    cin >> n;

    vector<Mountain> mountains(n);
    for (int i = 0; i < n; i++) {
        cin >> mountains[i].x >> mountains[i].y;
    }
    sort(mountains.begin(), mountains.end());

    int rightmost = 0;
    int possible = 0;
    for (int i = 0; i < n; i++) {
        int cur_right = mountains[i].x + mountains[i].y;
        if (cur_right > rightmost) {
            if (!(i > 0 && mountains[i].y - mountains[i].x == mountains[i + 1].y - mountains[i + 1].x)) {
                possible++;
            }
            rightmost = cur_right;
        }
    }

    cout << possible << "\n";
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
