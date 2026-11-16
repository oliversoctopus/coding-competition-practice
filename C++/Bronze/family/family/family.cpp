// family.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
bool between(int x, int c, int d) {
    if (c <= x && x <= d) {
        return true;
    }
    return false;
}
int main()
{
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a; int b; int c; int d;
    cin >> a >> b;
    cin >> c >> d;
    int result = (b - a) + (d - c);
    bool ab = between(a, c, d);
    bool bb = between(b, c, d);
    if (bb && !ab) {
        result -= b - c;
    }
    else if (bb && ab) {
        result -= b - a;
    }
    else if (!bb && ab) {
        result -= d - a;
    }
    cout << result;
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
