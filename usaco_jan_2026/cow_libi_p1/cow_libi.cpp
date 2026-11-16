#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool mapEmpty(const map<string, vector<int>>& m) {
    if (m.empty()) {
        return true;
    }
    for (const auto& pair : m) {
        if (!pair.second.empty()) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, c, n;
    cin>>t>>c;
    for (int a = 0; a < t; a++) {
        cin>>n;
        string left_str, right_str;
        cin>>left_str>>right_str;
        int left_j = 0, left_n = 0, right_j = 0, right_n = 0;
        map<string, vector<int>> state_cows;
        state_cows["JJ"];
        state_cows["JN"];
        state_cows["NJ"];
        state_cows["NN"];

        vector<string> cows;

        for (int i = 0; i < n; i++) {
            cows.push_back(string(1, left_str[i]) + right_str[i]);
            if (left_str[i] == 'J') {
                left_j++;
            } else {
                left_n++;
            }
            if (right_str[i] == 'J') {
                right_j++;
            } else {
                right_n++;
            }
            if (i == 0) {
                continue;
            }
            state_cows[string(1, left_str[i])+right_str[i]].push_back(i);
        }
        if (!(left_n == right_n && left_j == right_j)) {
            cout << "NO\n";
            continue;
        }
        int tot_j = left_j;
        int tot_n = left_n;

        vector<int> nums;
        vector<char> states;
        nums.push_back(0);
        states.push_back('J');
        int latest_num = 0;
        int latest_state = 'J';
        bool success = true;

        while (!mapEmpty(state_cows)) {
            char needed = cows[latest_num][1];
            if (tot_j == 0) {
                // must get something that ends in N
                vector<int>& cur = state_cows[string(1,needed)+'N'];
                if (cur.size() == 0) {
                    success = false;
                    break;
                }

                nums.push_back(cur[cur.size()-1]);
                if (latest_state == 'J') {
                    states.push_back(needed);
                } else {
                    if (needed == 'N') {
                        states.push_back('J');
                    } else {
                        states.push_back('N');
                    }
                }
                cur.pop_back();
            } else if (tot_n == 0) {
                // must get something that ends in J
                vector<int>& cur = state_cows[string(1,needed)+'J'];
                if (cur.size() == 0) {
                    success = false;
                    break;
                }

                nums.push_back(cur[cur.size()-1]);
                if (latest_state == 'J') {
                    states.push_back(needed);
                } else {
                    if (needed == 'N') {
                        states.push_back('J');
                    } else {
                        states.push_back('N');
                    }
                }
                cur.pop_back();
            } else {
                // can choose ending in either N or J
                vector<int>* cur_ptr = &state_cows[string(1,needed)+'N'];
                if (cur_ptr->size() == 0) {
                    cur_ptr = &state_cows[string(1,needed)+'J'];
                }
                if (cur_ptr->size() == 0) {
                    success = false;
                    break;
                }
                vector<int>& cur = *cur_ptr;
                nums.push_back(cur[cur.size()-1]);
                if (latest_state == 'J') {
                    states.push_back(needed);
                } else {
                    if (needed == 'N') {
                        states.push_back('J');
                    } else {
                        states.push_back('N');
                    }
                }
                cur.pop_back();
            }
            latest_num = nums[nums.size()-1];
            latest_state = states[states.size()-1];
        }
        if (!success) {
            cout << "NO\n";
            continue;
        }
        char first_state = states[0];
        char last_state = latest_state;
        char last_pred = cows[latest_num][1];
        //cout << first_state << " " << last_state << " " << last_pred << "\n" << flush;
        if (last_state == 'J') {
            if (first_state != last_pred) {
                cout << "NO\n";
                continue;
            }
        } else {
            if (first_state == last_pred) {
                cout << "NO\n";
                continue;
            }
        }
        cout << "YES\n";
        if (c == 0) { continue; }

        for (int n : nums) {
            cout << (n+1) << " ";
        }
        cout << "\n";
        for (char s : states) {
            cout << s;
        }
        cout << "\n";
    }
}
