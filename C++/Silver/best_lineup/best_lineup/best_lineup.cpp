// best_lineup.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

vector<int> move(vector<int> arr, int i, int move_to) {
    int temp = arr[i];
    for (int j = i; j > move_to; j--) {
        arr[j] = arr[j - 1];
    }
    arr[move_to] = temp;
    return arr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        vector<vector<int>> candidates; // {index of candidate, value of previous, index of larger}
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < candidates.size();) {
                if (candidates[k][1] < a[j]) {
                    candidates.erase(candidates.begin() + k);
                }
                else {
                    k++;
                }
            }
            int max = -1;
            int max_i = -1;
            int k = j - 1;
            int larger_ind = -1;
            while (k >= 0) {
                if (a[k] >= a[j]) {
                    larger_ind = k;
                    break;
                }
                if (a[k] > max) {
                    max = a[k];
                    max_i = k;
                }
                k--;
            }
            if (max_i != -1) {
                candidates.push_back({ j, max, larger_ind });
            }
        }
        int max_val = -1;
        vector<int> max_vec = {};
        for (auto x : candidates) {
            if (a[x[0]] > max_val) {
                max_val = a[x[0]];
                max_vec = x;
            }
        }

        if (max_vec.size() > 0) {
            a = move(a, max_vec[0], max_vec[2] + 1);
        }
        vector<int> result;
        for (int x : a) {
            if (result.size() == 0 || result.back() >= x) {
                result.push_back(x);
            }
            else {
                result.pop_back();
                result.push_back(x);
            }
        }
        for (int i = 0; i < result.size(); i++) {
            if (i < result.size() - 1) {
                cout << result[i] << " ";
            }
            else {
                cout << result[i];
            }
        }
        cout << "\n";
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
