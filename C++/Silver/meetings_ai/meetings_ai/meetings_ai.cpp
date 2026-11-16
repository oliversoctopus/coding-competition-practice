#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("meetings.in");
    ofstream fout("meetings.out");

    int N, L;
    fin >> N >> L;

    vector<int> weights(N), positions(N), directions(N);
    int totalWeight = 0;

    for (int i = 0; i < N; i++) {
        fin >> weights[i] >> positions[i] >> directions[i];
        totalWeight += weights[i];
    }

    // Calculate when each cow reaches a barn
    vector<pair<int, int>> arrivals; // (time, weight)
    for (int i = 0; i < N; i++) {
        if (directions[i] == 1) { // Moving right
            arrivals.push_back({ L - positions[i], weights[i] });
        }
        else { // Moving left
            arrivals.push_back({ positions[i], weights[i] });
        }
    }

    // Sort by arrival time
    sort(arrivals.begin(), arrivals.end());

    // Find time T
    int timeT = 0;
    int sumWeight = 0;
    for (auto [time, weight] : arrivals) {
        sumWeight += weight;
        if (sumWeight * 2 >= totalWeight) {
            timeT = time;
            break;
        }
    }

    // Create separate lists for left-moving and right-moving cows
    vector<int> rightCows, leftCows;
    for (int i = 0; i < N; i++) {
        if (directions[i] == 1) {
            rightCows.push_back(positions[i]);
        }
        else {
            leftCows.push_back(positions[i]);
        }
    }

    // Sort positions
    sort(rightCows.begin(), rightCows.end());
    sort(leftCows.begin(), leftCows.end());

    // Count meetings
    int meetings = 0;
    for (int rightPos : rightCows) {
        for (int leftPos : leftCows) {
            if (rightPos < leftPos) {
                // Calculate meeting time
                double meetTime = (leftPos - rightPos) / 2.0;
                if (meetTime <= timeT) {
                    meetings++;
                }
            }
        }
    }

    fout << meetings << endl;

    return 0;
}