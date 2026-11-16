#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n;
    cin>>n;
    vector<vector<int>> cows;
    for (int i = 0; i < n; i++) {
        int time, sample;
        cin>>time>>sample;
        cows.push_back({-i, time, sample});
    }
    sort(cows.begin(), cows.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) {
            return a[0]>b[0];
        }
        return a[1]<b[1];
    });

    int max_time = 0;
    int t = 0;
    priority_queue<vector<int>> waiting;
    for (int i = 0; i < n; i++) {
        vector<int> cow = cows[i];
        if (t < cow[1]) {
            if (waiting.size() == 0) {
                t = cow[1] + cow[2];
            } else {
                vector<int> c2 = waiting.top();
                waiting.pop();
                int wait_time = t - c2[1];
                max_time = max(max_time, wait_time);
                t += c2[2];
                i--;
            }
        } else {
            waiting.push(cow);
        }
    }

    // process remaining cows
    while (waiting.size() > 0) {
        vector<int> cow = waiting.top();
        waiting.pop();
        max_time = max(max_time, t - cow[1]);
        t += cow[2];
    }

    cout << max_time << endl;
}