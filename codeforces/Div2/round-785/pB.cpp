#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    string s;
    cin >> s;
    set<char> S;
    for (int i = 0; i < s.length(); i++) {
        S.insert(s[i]);
    }
    for (int i = 0; i <= s.length()-S.size(); i++) {
        map<char, int> mp;
        for (int j = 0; j < S.size(); j++) {
            mp[s[i+j]]++;
            if (mp[s[i+j]] > 1) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--) {
        solve_subtask();
    }
    return 0;
}