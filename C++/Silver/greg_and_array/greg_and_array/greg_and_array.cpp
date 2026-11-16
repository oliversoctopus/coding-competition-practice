// greg_and_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) { cin >> a[i]; }
	vector<array<int, 3>> updates(m);
	for (array<int, 3> &update : updates) {
		cin >> update[0] >> update[1] >> update[2];
	}

	vector<long long> s(m + 2);
	vector<long long> add(n + 2, 0);
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		s[x]++;
		s[y + 1]--;
	}

	for (int i = 1; i <= m; i++) {
		// Apply prefix sums
		s[i] += s[i - 1];

		// At the same time compute the second difference array
		add[updates[i - 1][0]] += s[i] * updates[i - 1][2];
		add[updates[i - 1][1] + 1] -= s[i] * updates[i - 1][2];
	}

	for (int i = 1; i <= n; i++) {
		// Apply prefix sums
		add[i] += add[i - 1];
		cout << a[i] + add[i] << ' ';
	}
	cout << endl;
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
