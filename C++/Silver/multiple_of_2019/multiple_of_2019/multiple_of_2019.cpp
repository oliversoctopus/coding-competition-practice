// multiple_of_2019.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	int n = s.size();

	vector<long long> remainders(2019);
	int num = 0;
	int pow = 1;
	remainders[0] = 1;
	for (int i = n - 1; i >= 0; i--) {
		num = (num + pow * (s[i] - '0')) % 2019;
		remainders[num]++;
		pow = pow * 10 % 2019;
	}
	
	long long ans = 0;
	for (int i = 0; i < 2019; i++) {
		ans += (long long)remainders[i] * (remainders[i] - 1) / 2;
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
