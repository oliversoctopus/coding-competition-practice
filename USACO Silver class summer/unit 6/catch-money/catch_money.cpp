#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(const char* filename) {
    ifstream cin(filename);
    int n;
    cin >> n;
    vector<vector<int>> money;
    for (int i = 0; i < n; i++) {
        int f, e;
        cin >> f >> e;
        money.push_back({e, f});
    }
    sort(money.begin(), money.end());
    cin.close();

    priority_queue<int> pq;
    int count = 0;
    int total = 0;
    for (auto b : money) {
        pq.push(-b[1]); // negative value
        count++;
        total += b[1];
        if (count > b[0]) {
            int minim = -pq.top();
            pq.pop();
            total -= minim;
            count--;
        }
    }
    cout << total << endl;
}

int main() {
    solve("01.in");
    solve("02.in");
    solve("03.in");
    solve("04.in");
    solve("05.in");
    solve("06.in");
    solve("07.in");
    solve("08.in");
    solve("09.in");
    solve("10.in");
}