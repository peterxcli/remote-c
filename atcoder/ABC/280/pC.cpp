#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < min(s.size(), t.size()); i++) {
        if (s[i] != t[i]) {
            cout << i+1 << "\n";
            return 0;
        }
    }
    cout << min(s.size(), t.size()) + 1 << "\n";
    return 0;
}