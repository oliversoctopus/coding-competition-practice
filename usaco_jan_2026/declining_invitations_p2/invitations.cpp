#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,c;
    cin>>n>>c;
    vector<int> crit_ppl;
    for (int i = 0; i < c; i++) {
        int a;
        cin>>a;
        crit_ppl.push_back(a);
    }
    vector<int> remove_order;
    for (int i = 0; i < n; i++) {
        int a;
        cin>>a;
        remove_order.push_back(a-1);
    }
    vector<int> valid(n); // 0 is valid, 1 is NOT VALID
    vector<vector<int>> crit_bins(c); // in each bin, ppl will be added in order
    for (int i = 0; i < n; i++) {
        int n_i;
        cin>>n_i;
        for (int j = 0; j < n_i; j++) {
            int crit;
            cin>>crit;
            crit--;
            crit_bins[crit].push_back(i);
        }
    }

    vector<int> selected(n, -1); // -1 is unselected, all else is selected b/c of bin i
    vector<int> bin_indexes(c, -1); // the last index at which a person was selected, -1 means none selected
    for (int cur = 0; cur < c; cur++) {
        vector<int> bin = crit_bins[cur];
        int n_sel = 0;
        for (int p = 0; p < bin.size(); p++) {
            if (n_sel == crit_ppl[cur]) {
                break;
            }
            if (selected[bin[p]] == -1) {
                selected[bin[p]] = cur;
                n_sel++;
                bin_indexes[cur] = p;
            }
        }
    }

    int cur_sum = 0;
    for (int i = 0; i < n; i++) {
        if (selected[i] != -1) {
            cur_sum += (i+1);
        }
    }
    for (int person : remove_order) {
        cout << cur_sum << "\n";
        if (selected[person] == -1) {
            valid[person] = 1;
        } else {
            cur_sum -= (person+1);
            int bin = selected[person];
            int ind = bin_indexes[bin];
            if (ind + 1 >= crit_bins[bin].size()) {
                // out of people in the bin so nothing happens
            } else {
                ind++;
                int next_in_bin = crit_bins[bin][ind];
                while (ind < crit_bins[bin].size() && (valid[next_in_bin] == 1 || (selected[next_in_bin] < bin && selected[next_in_bin] != -1))) {
                    ind++;
                    next_in_bin = crit_bins[bin][ind];
                }
                bin_indexes[bin] = ind;
                if (ind < crit_bins[bin].size() && selected[next_in_bin] == -1) {
                    selected[next_in_bin] = bin;
                    cur_sum += (next_in_bin+1);
                } else if (ind < crit_bins[bin].size()) {
                    while (true) {
                        int temp = selected[next_in_bin];
                        selected[next_in_bin] = bin;
                        bin = temp;
                        ind = bin_indexes[bin];
                        if (ind + 1 >= crit_bins[bin].size()) {
                            // out of people, nothing happens
                            break;
                        }
                        ind++;
                        next_in_bin = crit_bins[bin][ind];
                        while (ind < crit_bins[bin].size() && (valid[next_in_bin] == 1 || (selected[next_in_bin] < bin && selected[next_in_bin] != -1))) {
                            ind++;
                            next_in_bin = crit_bins[bin][ind];
                        }
                        bin_indexes[bin] = ind;
                        if (ind < crit_bins[bin].size() && selected[next_in_bin] == -1) {
                            selected[next_in_bin] = bin;
                            cur_sum += (next_in_bin+1);
                            break;
                        }
                    }
                }
            }
        }
    }
}