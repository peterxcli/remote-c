//https://codeforces.com/contest/1478/problem/0
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0), ios_base::sync_with_stdio(0);
    int t, n;
    vector<int> a, last;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n), last.clear();
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        last.push_back(a[0]);
        for (int i = 1; i < n; i++) {
            int add = 1;
            for (int j = 0; j < last.size(); j++) {
                if (last[j] < a[i]) {
                    last[j] = a[i];
                    add = 0;
                    break;
                } 
            }
            if (add) last.push_back(a[i]);
        }
        cout << last.size() << "\n";
    }
}