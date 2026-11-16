#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen("teamwork.in", "w", stdout);
    int N = 1e4;
    int K = 1e3;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> int_dist(1, 1e5);
    cout << N << " " << K << "\n";
    for (int i = 0; i < N; i++) {
        int random_int = int_dist(gen);
        cout << random_int << "\n";
    }
}