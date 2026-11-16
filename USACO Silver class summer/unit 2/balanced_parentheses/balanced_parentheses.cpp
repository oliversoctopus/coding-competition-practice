#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<char> st;
        bool success = true;
        for (char c : s) {
            if (c == '[' || c == '(') {
                st.push_back(c);
            } else {
                char last = st[st.size() - 1];
                if (c == ']' && last == '[') {
                    if (st.empty()) {
                        success = false;
                        break;
                    }
                    st.pop_back();
                } else if (c == ')' && last == '(') {
                    if (st.empty()) {
                        success = false;
                        break;
                    }
                    st.pop_back();
                } else {
                    success = false;
                    break;
                }
            }
        }
        if (success && st.empty()) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
}
