// div7.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

bool slidingWindow(vector<long long> cows, int size) {
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += cows[i];
    }
    if (sum % 7 == 0) {
        return true;
    }
    for (int i = 1; i < (cows.size() - size); i++) {
        sum -= cows[i - 1];
        sum += cows[i + size - 1];

        if (sum % 7 == 0) {
            return true;
        }
    }
    return false;
}

int main()
{
    ofstream fout("div7.out");
    ifstream fin("div7.in");

    int n;
    fin >> n;

    vector<long long> cows;
    for (int i = 0; i < n; i++) {
        long long c;
        fin >> c;
        cows.push_back(c);
    }

    for (int s = cows.size(); s > 0; s--) {
        if (slidingWindow(cows, s)) {
            fout << s << "\n";
            break;
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
