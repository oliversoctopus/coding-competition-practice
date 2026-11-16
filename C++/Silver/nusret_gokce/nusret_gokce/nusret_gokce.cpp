// nusret_gokce.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    int n, m;
    cin >> n >> m;

    vector<int> salt;

    for (int i = 0; i < n; i++) {
        int cur;
        cin >> cur;
        salt.push_back(cur);
    }

    for (int i = 0; i < n; i++) {
        if (n == 1) {
            break;
        }
        if (i == 0) {
            salt[i] = max(salt[i], salt[i + 1] - m);
        }
        else if (i == n - 1) {
            salt[i] = max(salt[i], salt[i - 1] - m);
        }
        else {
            salt[i] = max(max(salt[i], salt[i + 1] - m), salt[i - 1] - m);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (n == 1) {
            break;
        }
        if (i == 0) {
            salt[i] = max(salt[i], salt[i + 1] - m);
        }
        else if (i == n - 1) {
            salt[i] = max(salt[i], salt[i - 1] - m);
        }
        else {
            salt[i] = max(max(salt[i], salt[i + 1] - m), salt[i - 1] - m);
        }
    }

    for (auto i : salt) {
        cout << i << " ";
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
