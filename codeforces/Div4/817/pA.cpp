// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;


void solve_subtask() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    map<char, int> mp;
    mp['T']++, mp['i']++, mp['m']++, mp['u']++, mp['r']++;
    for (int i = 0; i < n; i++) {
        if (mp.find(str[i]) != mp.end()) mp.erase(str[i]);
        else {cout << "no\n"; return;}
    }
    if (mp.empty()) cout << "yes\n";
    else cout << "no\n";
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