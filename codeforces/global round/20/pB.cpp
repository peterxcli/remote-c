#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s; cin >> s;
    int a = 0;
    for (int i = 0; i < s.length(); i++) {
        auto x = s[i];
        a += (x == 'A' ? 1 : -1);
        if (a<0) {cout << "NO\n";return;}
    }
    if (s.length() > 1 && s[0] != 'B' && s[s.length()-1] != 'A') cout << "YES\n";
    else cout << "NO\n";
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int cnt = 1;
    cin >> cnt;
    while (cnt--) solve();
}