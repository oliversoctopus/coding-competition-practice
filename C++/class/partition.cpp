#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int partition(int low, int high, vector<int>& ls) {
    int pivot = ls[high];
    int i = low - 1;
    int j = low;
    for (; j < high; j++) {
        if (ls[j] < pivot) {
            int temp = ls[i + 1];
            ls[i+1] = ls[j];
            ls[j] = temp;
            i++;
        }
    }
    int temp = ls[i+1];
    ls[i+1] = ls[high];
    ls[high] = temp;
    return i+1;
}

void test(vector<int> t) {
    cout << partition(0, t.size() - 1, t) << endl;
    for (int i : t) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> test1 = {5,4,3,2,1};
    test(test1);
    test({4, 5, 6, 2, 5});
    test({1, 2, 5, 4, 3});
}