// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) if (a[i] != 0) cnt++;
    map<int, int> mp;
    for (int i = 0; i < n; i++) mp[a[i]]++;
    if (cnt != n) cout << cnt << "\n";
    else {
        for (auto x : mp) {
            if (x.second >= 2) {
                cout << n << "\n";
                return;
            }
        }
        cout << n+1 << "\n";
    }
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