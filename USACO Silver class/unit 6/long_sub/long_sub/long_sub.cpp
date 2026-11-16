// long_sub.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    //freopen("08.in", "r", stdin);
    string s;
    cin >> s;
    //cout << s << "\n";

    vector<char> subsequence;
    for (int i = s.size() - 1; i >= 0; i--) {
        int ind = -1;
        char elem = s[i];
        for (int j = subsequence.size() - 1; j >= 0; j--) {
            if (subsequence[j] == elem) {
                ind = j;
                break;
            }
        }
        if (ind == -1) {
            subsequence.push_back(elem);
        }
        else {
            if (subsequence[subsequence.size() - 1] > elem) {
                subsequence.erase(subsequence.begin() + ind);
                subsequence.push_back(elem);
            }
        }
    }
    ll sum = 0;
    for (int i = 0; i < subsequence.size(); i++) {
        int elem_int = subsequence[i] - 'a';
        ll prod = 1;
        for (int j = 0; j < i; j++) {
            prod *= 26;
            prod %= 1000000007;
        }
        ll res = elem_int * prod % 1000000007;
        cout << elem_int << " " << res << "\n";
        sum += res;
        sum %= 1000000007;
    }
    cout << sum << "\n";
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
