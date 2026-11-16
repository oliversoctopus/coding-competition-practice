// farmer_john_favorite_operation.cpp : This file contains the 'main' function. Program execution begins and ends there.
// AI
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
    }

    // Precompute the positions where a[i] == b[i]
    vector<int> original_matches;
    for (int i = 0; i < N; ++i) {
        if (a[i] == b[i]) {
            original_matches.push_back(i);
        }
    }

    // Total number of segments is N*(N+1)/2
    long long total_segments = static_cast<long long>(N) * (N + 1) / 2;

    // Initialize the total matches
    long long total_matches = 0;

    // For each position i, calculate the number of segments (l, r) that include i
    // and result in a[i] == b[i] after reversal
    for (int i = 0; i < N; ++i) {
        // The number of segments that include i is (i+1) * (N - i)
        long long segments_including_i = static_cast<long long>(i + 1) * (N - i);

        // Calculate the number of segments where after reversal, a[i] == b[i]
        // This happens if the reversal swaps a[i] with a[j] where j is such that a[j] == b[i]
        // and i and j are symmetric around the midpoint of the segment
        // Alternatively, if the segment does not include i, then a[i] remains the same

        // First, count the number of segments that do not include i
        long long segments_not_including_i = total_segments - segments_including_i;

        // If a[i] == b[i], then all segments not including i contribute 1
        if (a[i] == b[i]) {
            total_matches += segments_not_including_i;
        }

        // Now, for segments including i, we need to find the number of segments where after reversal, a[i] == b[i]
        // The reversal of a segment [l, r] swaps a[l+k] with a[r-k] for k from 0 to (r-l)/2
        // For position i, if it is in the segment [l, r], then after reversal, a[i] will be a[l + r - i]
        // So, we need a[l + r - i] == b[i]

        // To find the number of segments [l, r] including i such that a[l + r - i] == b[i]
        // We can iterate over all possible l and r, but that's O(N^2), which is too slow

        // Instead, we can precompute for each i, the positions j such that a[j] == b[i]
        // Then, for each such j, find the number of segments [l, r] including i and j, and l + r - i == j

        // Let's precompute the positions where a[j] == b[i]
        vector<int> positions_with_b_i;
        for (int j = 0; j < N; ++j) {
            if (a[j] == b[i]) {
                positions_with_b_i.push_back(j);
            }
        }

        // Now, for each j in positions_with_b_i, find the number of segments [l, r] including i and j, and l + r - i == j
        // This implies l + r = i + j
        // Also, l <= i <= r and l <= j <= r

        // So, l <= min(i, j) and r >= max(i, j)
        // And l + r = i + j

        // Let's solve for l and r:
        // l + r = i + j
        // l <= min(i, j)
        // r >= max(i, j)

        // From l + r = i + j, we can express r = i + j - l
        // Substitute into r >= max(i, j):
        // i + j - l >= max(i, j)
        // => l <= i + j - max(i, j)

        // Also, l <= min(i, j)

        // So, l <= min(i, j, i + j - max(i, j))

        // But i + j - max(i, j) = min(i, j)
        // So l <= min(i, j)

        // Similarly, r = i + j - l >= max(i, j)
        // => l <= i + j - max(i, j)

        // So, l can range from max(1, min(i, j) - (i + j - max(i, j)) + 1) to min(i, j)

        // Wait, perhaps it's easier to iterate over possible l and r

        // Alternatively, we can note that for each j, the number of segments [l, r] including i and j, and l + r = i + j
        // is equal to the number of l such that l <= i, l <= j, and r = i + j - l >= j

        // So, l can range from max(1, i + j - N) to min(i, j)

        // Let's implement this

        for (int j : positions_with_b_i) {
            if (j == i) {
                // If j == i, then l + r = 2i
                // Also, l <= i <= r
                // So l can range from 1 to i, and r = 2i - l >= i
                // So l <= i
                // The number of such l is i
                total_matches += i;
            }
            else {
                // l + r = i + j
                // l <= min(i, j)
                // r = i + j - l >= max(i, j)
                // So l <= i + j - max(i, j)
                // Also, l >= 1
                // So l ranges from max(1, i + j - N) to min(i, j, i + j - max(i, j))

                int lower_l = max(1, i + j - (N - 1));
                int upper_l = min(i, j);

                if (lower_l > upper_l) {
                    continue;
                }

                total_matches += upper_l - lower_l + 1;
            }
        }
    }

    cout << total_matches << endl;

    return 0;
}
/*
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

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int j = 0; j < n; j++) {
            ll val;
            cin >> val;
            val %= m;
            if (val > m / 2) {
                val -= m;
            }
            if (val < -(m / 2)) {
                val += m;
            }
            val -= m - 1;
            if (val > m / 2) {
                val -= m;
            }
            if (val < -(m / 2)) {
                val += m;
            }
            a[j] = val;
        }
        sort(a.begin(), a.end());
        ll x = 0;
        if (n % 2 == 0) {
            x = (a[n / 2] + a[n / 2 - 1]) / 2;
        }
        else {
            x = a[n / 2];
        }
        ll b_val = 0;
        for (int j = 0; j < n; j++) {
            ll val = a[j] - x;
            if (val < -(m / 2)) {
                val += m;
            }
            if (val > m / 2) {
                val -= m;
            }
            b_val += abs(val);
        }

        cout << b_val << "\n";
    }
}
*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
