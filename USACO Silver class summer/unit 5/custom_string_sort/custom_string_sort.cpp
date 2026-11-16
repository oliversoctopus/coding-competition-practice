#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool verify(string s1, string s2) {
    vector<int> freq(26, 0);
    for (char c : s1) {
        freq[c-'a']++;
    }

    string modified = "";
    for (char c : s2) {
        if (freq[c-'a'] > 0) {
            modified += c;
        }
    }

    int pointer = 0;
    for (char c : s1) {
        int num = freq[c-'a'];
        for (int i = 0; i < num; i++) {
            if (modified[pointer] != c) {
                return false;
            }
            pointer++;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s1;
    string s2;
    cin >> s1 >> s2;

    vector<int> freq(26, 0);
    for (char c : s2) {
        freq[c-'a']++;
    }

    string result = "";
    for (char c : s1) {
        int num = freq[c-'a'];
        for (int i = 0; i < num; i++) {
            result += c;
        }
        freq[c-'a'] = 0;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < freq[i]; j++) {
            result += (char) ('a'+i);
        }
    }
    cout << result << "\n";
    bool v = verify(s1, result);
    cout << v << "\n";
}