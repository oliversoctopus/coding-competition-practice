// gcd_blackboard.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;

int arr[maxN];
int prefGcd[maxN];  // prefGcd[i] = GCD of a1,a2, ..., ai
int suffGcd[maxN];  // suffGcd[i] = GCD of ai, ai+1, ..., an
int N;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i) cin >> arr[i];

	prefGcd[0] = 0;
	suffGcd[N + 1] = 0;

	for (int i = 1; i <= N; ++i) { prefGcd[i] = gcd(prefGcd[i - 1], arr[i]); }

	for (int i = N; i >= 1; --i) { suffGcd[i] = gcd(suffGcd[i + 1], arr[i]); }

	int res = 0;
	for (int i = 1; i <= N; ++i) {
		res = max(res, gcd(prefGcd[i - 1], suffGcd[i + 1]));
	}
	cout << res << '\n';
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
