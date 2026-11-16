#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    set<int> unique;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        unique.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        a.push_back(a[i]); // duplicate to make cycling easy
    }
    vector<int> right(n);
    map<int,int> un_counts;
    for (int num : unique) {
        un_counts[num] = 0;
    }
    int num_max = unique.size();
    int start = 0;
    int end = 0;
    int cur_num = 1;
    un_counts[a[start]] = 1;
    for (;start < n; start++) {
        while (cur_num < num_max) {
            end++;
            int new_n = a[end];
            if (un_counts[new_n] == 0) {
                cur_num++;
                un_counts[new_n] = 1;
            } else {
                un_counts[new_n]++;
            }
        }
        right[start] = end-start;
        int s_num = a[start];
        un_counts[s_num]--;
        if (un_counts[s_num] == 0) {
            cur_num--;
        } else if (un_counts[s_num] < 0) {
            cout << "FATAL ERROR LOGIC ERROR\n";
        }
    }

    vector<int> left(n);
    map<int,int> un_counts_left;
    for (int num : unique) {
        un_counts_left[num] = 0;
    }
    num_max = unique.size();
    start = 2*n-1;
    end = 2*n-1;
    cur_num = 1;
    un_counts_left[a[start]] = 1;
    for (start = 2*n-1; start >= n; start--) {
        while (cur_num < num_max) {
            end--;
            int new_n = a[end];
            if (un_counts_left[new_n] == 0) {
                cur_num++;
                un_counts_left[new_n] = 1;
            } else {
                un_counts_left[new_n]++;
            }
        }
        left[start-n] = start-end;
        int s_num = a[start];
        un_counts_left[s_num]--;
        if (un_counts_left[s_num] == 0) {
            cur_num--;
        } else if (un_counts_left[s_num] < 0) {
            cout << "FATAL ERROR LOGIC ERROR\n";
        }
    }

    for (int i = 0; i < n; i++) {
        cout << min(left[i], right[i]) << " ";
    }
    cout << "\n";
}
