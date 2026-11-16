// calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    getline(cin, s);

    vector<int> nums;
    vector<char> ops;

    int pos = 0;
    while (pos < s.size()) {
        if (s[pos] == ' ') {
            pos++;
            continue;
        }
        
        int cur = 0;
        while (pos < s.size() && isdigit(s[pos])) {
            cur = cur * 10 + (s[pos] - '0');
            pos++;
        }
        
        if (ops.back() == '*') {
            nums.back() *= cur;
            ops.pop_back();
        }
        else if (ops.back() == '/') {
            nums.back() /= cur;
            ops.pop_back();
        }
        else {
            nums.push_back(cur);
        }

        ops.push_back(s[pos]);
    }

    cout << nums.size() << " " << ops.size() << "\n";

    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (ops[i - 1] == '+') {
            ans += nums[i];
        }
        else {
            ans -= nums[i];
        }
    }
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
