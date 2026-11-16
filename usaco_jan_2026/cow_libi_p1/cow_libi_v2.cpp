#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// turns something like JJ,JJ,JJ into J,J,J (the actual states of the cows instead of left-right thing)
string make_states(vector<string> cows) {
    string result = "J"; // first cow is J arbitrarily
    for (int i = 0; i < cows.size()-1; i++) {
        // "JJ", the right_val would be J
        // the last cow has the left-right configuration of cows[i]
        // check the right value of the cow's configuration with the actual state of the cow to construct the next one
        // if cow is J, right_val is J, the next one is also J
        // if cow is N, right_val is J, the next cow is N
        char right_val = cows[i][1];
        char last_cow = result[result.size()-1];
        if (last_cow == 'J') {
            // the new cow is the right val
            result += right_val;
        } else {
            // the new cow is opposite of right val
            if (right_val == 'J') {
                result += 'N';
            } else {
                result += 'J';
            }
        }
    }
    return result;
}

int main() {
    ifstream cin("4.in");
    ofstream cout("4_ours.out");
    int t, c;
    cin>>t>>c;
    for (int a = 0; a < t; a++) {
        int n;
        cin>>n;
        string lefts, rights;
        cin>>lefts>>rights;
        map<string, vector<int>> cows;
        cows["JJ"]; cows["JN"]; cows["NJ"]; cows["NN"];
        for (int i = 0; i < lefts.size(); i++) {
            string configuration = string(1, lefts[i]) + rights[i];
            cows[configuration].push_back(i+1); // i+1 is the cow number because it goes from 1 to N
        }
        if ((cows["JN"].size() + cows["NN"].size()) % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        if (cows["JN"].size() != cows["NJ"].size()) {
            cout << "NO\n";
            continue;
        }

        if (cows["JJ"].size() > 0 && cows["NN"].size() > 0 && cows["JN"].size() == 0 && cows["NJ"].size() == 0) {
            cout << "NO\n";
            continue;
        }

        if (c == 0) {
            cout << "YES\n";
            continue;
        }
        if (cows["JJ"].size() == n) {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << "\n";
            for (int i = 0; i < n; i++) {
                cout << "J";
            }
            cout << "\n";
            continue;
        } else if (cows["NN"].size() == n) {
            cout << "YES\n";

            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << "\n";
            // the cows alternate between J and N
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) {
                    cout << "J";
                } else {
                    cout << "N";
                }
            }
            cout << "\n";
            continue;
        }
        cout << "YES\n";
        // now print the number IDs before printing the cow states
        // print all the IDs of the JJ cows
        for (int cow : cows["JJ"]) {
            cout << cow << " ";
        }
        // print the last JN
        cout << cows["JN"][cows["JN"].size()-1] << " ";
        // print all the NN's
        for (int cow : cows["NN"]) {
            cout << cow << " ";
        }
        // print all but 1 of the JN-NJ pairs
        for (int i = 0; i < cows["JN"].size()-1; i++) {
            cout << cows["NJ"][i] << " " << cows["JN"][i] << " ";
        }
        // print the last NJ
        cout << cows["NJ"][cows["NJ"].size()-1] << " \n";

        // build the configuration
        vector<string> configs;
        for (int i = 0; i < cows["JJ"].size(); i++) {
            configs.push_back("JJ");
        }
        // add the JN transition
        configs.push_back("JN");
        // add all the NN's
        for (int i = 0; i < cows["NN"].size(); i++) {
            configs.push_back("NN");
        }
        // we need all but 1 JN-NJ pair so we do the number of JN's minus one as the limit
        for (int i = 0; i < cows["JN"].size()-1; i++) {
            configs.push_back("NJ");
            configs.push_back("JN");
        }
        // add the NJ transition
        configs.push_back("NJ");
        // construct the states of the cows and then print it
        string states = make_states(configs);
        cout << states << "\n";
    }
    
    cin.close();
}