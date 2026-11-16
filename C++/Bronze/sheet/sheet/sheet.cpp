// sheet.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int inter_area(vector<int> s1, vector<int> s2) {
    int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
    int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

    return ((min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x)) *
        (min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y)));
}

int main()
{
    //freopen("filename.in", "r", stdin);
    //freopen("filename.out", "w", stdout);
    int x1; int y1; int x2; int y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<int> white = { x1, y1, x2, y2 };
    cin >> x1 >> y1 >> x2 >> y2;
    vector<int> b1 = { x1, y1, x2, y2 };
    cin >> x1 >> y1 >> x2 >> y2;
    vector<int> b2 = { x1, y1, x2, y2 };
    for (int i : white) {
        cout << i << "\n";
    }
    cout << "\n";
    for (int i : b1) {
        cout << i << "\n";
    }
    cout << "\n";
    for (int i : b2) {
        cout << i << "\n";
    }
    cout << "\n";
    int obstructed_area = inter_area(white, b1) + inter_area(white, b2) - inter_area(b1, b2);
    int white_area = (white[3] - white[1]) * (white[2] - white[0]);
    if (obstructed_area >= white_area) {
        cout << "YES";
    }
    else {
        cout << "NO";
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
