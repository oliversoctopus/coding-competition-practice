/*
sort cow positions

size = cows[N-1] - cows[0] + 1
first move that least decreases size
then: each next move decreases size by 1
L - M + 1 = N
max_moves = L - N + 1 where L is the max possible size after first move
max_moves = max(cows[N-1] - cows[1], cows[N-2] - cows[0]) - N + 2 (first move)

min_moves = # of empty spaces of [block of N with least empty spaces]
2 exceptions: if everything is contiguous at beginning but 1, if everything is contiguous at the end but 1; both exceptions need 2 moves
use 2 pointers to find block with least number of empty spaces (assume block starts at the left index)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    string FILE_NAME = "herding";
    ifstream cin(FILE_NAME + ".in");
    ofstream cout(FILE_NAME + ".out");
    int N;
    cin>>N;
    vector<int> cows(N);
    for (int &c : cows) cin >> c;
    sort(cows.begin(), cows.end());
    int max_moves = max(cows[N-1] - cows[1], cows[N-2] - cows[0]) - N + 2;
    
    int left = 0;
    int right = 0; // [left, right)
    int min_moves = 1e6;
    while (left < N && right < N) {
        // diff must be <N (if diff=N, the block is size N+1)
        while (right < N && cows[right] - cows[left] < N) right++;
        int n_cows_in_block = right - left;
        if (n_cows_in_block == N - 1 && cows[right-1] - cows[left] == N - 2)
            min_moves = min(min_moves, 2);
        else
            min_moves = min(min_moves, N - n_cows_in_block);
        left++;
    }
    cout << min_moves << "\n" << max_moves << "\n";
}