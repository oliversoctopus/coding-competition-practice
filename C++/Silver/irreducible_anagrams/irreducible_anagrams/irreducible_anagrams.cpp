// irreducible_anagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    string s;
    cin >> s;
    vector<int> chars(26, 0);

    vector<vector<int>> psum;
    psum.push_back(chars);
    for (auto i : s) {
        int a = (int)i - 'a';
        chars[a]++;
        psum.push_back(chars);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == r) {
            cout << "Yes" << "\n";
            continue;
        }
        if (s[l] != s[r]) {
            cout << "Yes" << "\n";
            continue;
        }
        vector<int> left = psum[l];
        vector<int> right = psum[r + 1];

        int unique = 0;
        for (int j = 0; j < 26; j++) {
            int val = right[j] - left[j];
            if (val > 0) {
                unique++;
            }
        }

        if (unique >= 3) {
            cout << "Yes" << "\n";
        }
        else {
            cout << "No" << "\n";
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
