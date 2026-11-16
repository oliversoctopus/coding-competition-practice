#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> merge(vector<int> left_s, vector<int> right_s) {
    int i = 0; int j = 0;
    vector<int> merged;
    while (i < left_s.size() && j < right_s.size()) {
        if (left_s[i] < right_s[j]) {
            merged.push_back(left_s[i]);
            i++;
        } else {
            merged.push_back(right_s[j]);
            j++;
        }
    }
    for (; i < left_s.size(); i++) {
        merged.push_back(left_s[i]);
    }
    for (; j < right_s.size(); j++) {
        merged.push_back(right_s[j]);
    }
    return merged;
}

vector<int> merge_sort(vector<int> ls) {
    if (ls.size() <= 1) {
        return ls;
    }

    int mid = ls.size() / 2;
    vector<int> left(ls.begin(), ls.begin() + mid);
    vector<int> right(ls.begin() + mid, ls.end());
    
    vector<int> left_sorted = merge_sort(left);
    vector<int> right_sorted = merge_sort(right);

    return merge(left_sorted, right_sorted);
}

// --- Quick Sort Implementation ---

// Partition function (Lomuto partition scheme)
int partition(vector<int>& ls, int low, int high) {
    int pivot = ls[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (ls[j] < pivot) {
            i++;
            swap(ls[i], ls[j]);
        }
    }
    swap(ls[i + 1], ls[high]);
    return i + 1;
}

// Recursive quick_sort function
void quick_sort_recursive(vector<int>& ls, int low, int high) {
    if (low < high) {
        int pivot_index = partition(ls, low, high);
        quick_sort_recursive(ls, low, pivot_index - 1);
        quick_sort_recursive(ls, pivot_index + 1, high);
    }
}

// Wrapper for easy calling
void quick_sort(vector<int>& ls) {
    if (ls.empty()) return;
    quick_sort_recursive(ls, 0, ls.size() - 1);
}

int main() {
    vector<int> test = {5, 4, 3, 2, 1};
    vector<int> t2 = {3, 8, 1, 5, 7, 2, 5, 3, 67};

    cout << "--- Merge Sort ---" << endl;
    vector<int> t_s = merge_sort(test);
    for (int i : t_s) {
        cout << i << " ";
    }
    cout << "\n";

    cout << "\n--- Quick Sort ---" << endl;
    quick_sort(t2); // Sorts in-place
    for (int i : t2) {
        cout << i << " ";
    }
    cout << "\n";
}