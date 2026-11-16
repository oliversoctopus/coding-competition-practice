#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int m;
    cin>>m;
    int limit = m*m*2;
    vector<bool> bisq_lookup(125001);
    vector<int> bisq;
    for (int i = 0; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            if (!bisq_lookup[i*i+j*j])
                bisq.push_back(i*i+j*j);
            bisq_lookup[i*i+j*j] = true;
        }
    }

    sort(bisq.begin(), bisq.end());
    /* for (int num : bisq) {
        cout << num << " ";
    }
    cout<<"\n"; */
    int success = 0;
    for (int i = 0; i < bisq.size(); i++) {
        for (int j = i+1; j < bisq.size(); j++) {
            int n1 = bisq[i];
            int n2 = bisq[j];
            int d = n2-n1;
            if (n1+(n-1)*d > limit) break;
            if (bisq_lookup[n1+(n-1)*d] == false) continue;
            int cur_n = 2;
            while (true) {
                int new_n = n2+d;
                if (new_n > limit)
                    break;
                if (cur_n == n)
                    break;
                if (bisq_lookup[new_n] == true) {
                    cur_n++;
                    n2 = new_n;
                } else {
                    break;
                }
            }
            if (cur_n == n) {
                success++;
            }
        }
    }
    cout << success << "\n";
}
