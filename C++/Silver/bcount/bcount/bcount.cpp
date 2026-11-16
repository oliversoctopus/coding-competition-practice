// bcount.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

vector<int> psum(vector<int> a) {
    vector<int> result((int)size(a) + 1);
    for (int i = 0; i < (int)size(a); ++i) result[i + 1] = result[i] + a[i];
    return result;
}

int main()
{
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n; int q;
    cin >> n >> q;
    vector<int> holsteins;
    vector<int> guernseys;
    vector<int> jerseys;
    for (int i = 0; i < n; i++) {
        int new_cow = 0;
        cin >> new_cow;
        int h = 0; int g = 0; int j = 0;
        if (new_cow == 1) {
            h++;
        }
        else if (new_cow == 2) {
            g++;
        }
        else if (new_cow == 3) {
            j++;
        }
        holsteins.push_back(h);
        guernseys.push_back(g);
        jerseys.push_back(j);
    }
    vector<int> h_psum = psum(holsteins);
    vector<int> g_psum = psum(guernseys);
    vector<int> j_psum = psum(jerseys);

    // query
    for (int i = 0; i < q; i++) {
        int a; int b;
        cin >> a >> b;
        int h_n = h_psum[b] - h_psum[a-1];
        int g_n = g_psum[b] - g_psum[a-1];
        int j_n = j_psum[b] - j_psum[a-1];
        cout << h_n << " " << g_n << " " << j_n << "\n";
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
