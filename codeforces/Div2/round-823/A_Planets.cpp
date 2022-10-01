// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    vector<int> a[105];
    int n, c; cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        a[tmp].emplace_back(i);
    }
    int ans = 0;
    for (int i = 0; i < 105; i++) {
        if (a[i].size() > c) ans += c;
        else ans += a[i].size();
    }
    cout << ans << "\n";
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