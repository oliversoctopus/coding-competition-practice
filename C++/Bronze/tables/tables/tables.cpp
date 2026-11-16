// tables.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int w; int h;
        cin >> w >> h;
        int x1; int y1; int x2; int y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int wt2; int ht2;
        cin >> wt2 >> ht2;
        int wt1 = x2 - x1;
        int ht1 = y2 - y1;
        int wmove = 1000000000;
        if (wt1 + wt2 <= w) {
            //cout << "Width";
            int left_dist = x1;
            int right_dist = w - x2;
            wmove = max(wt2 - max(left_dist, right_dist), 0);
        }
        int hmove = 1000000000;
        if (ht1 + ht2 <= h) {
            //cout << "Length";
            int top_dist = h - y2;
            int bottom_dist = y1;
            hmove = max(ht2 - max(top_dist, bottom_dist), 0);
        }
        //cout << wmove << hmove;
        int dist = min(wmove, hmove);
        if (dist == 1000000000) {
            cout << -1 << "\n";
        }
        else {
            cout << dist << "\n";
        }
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
