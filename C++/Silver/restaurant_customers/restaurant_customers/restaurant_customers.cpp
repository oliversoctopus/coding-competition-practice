// restaurant_customers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> times;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		times.push_back({ start, 1 });
		times.push_back({ end + 1, -1 });
	}

	sort(times.begin(), times.end());

	int curr = 0;
	int at = 0;
	// Stores how much the # of people in the restaurant changes each time step
	vector<int> ppl_change(2 * n);
	// Compress the starting & ending events into a single array
	for (int i = 0; i < 2 * n; i++) {
		if (i == 0) {
			times[i].first = 0;
		}
		else if (times[i].first > curr) {
			at++;
			curr = times[i].first;
		}
		ppl_change[at + 1] += times[i].second;
	}

	// Build our prefix sum array
	vector<int> ppl_amt(2 * n + 1);
	for (int i = 1; i < 2 * n + 1; i++) {
		ppl_amt[i] = ppl_change[i - 1] + ppl_amt[i - 1];
	}

	// Our answer is just the maximum of the prefix sum array
	int max_ppl = 0;
	for (int i = 0; i < 2 * n + 1; i++) { max_ppl = max(max_ppl, ppl_amt[i]); }

	cout << max_ppl << endl;
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
