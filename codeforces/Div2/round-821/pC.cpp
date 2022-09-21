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
    vector<int> a(n);
    vector<pair<int, int> > ans;
    for (auto &x : a) cin >> x;
    if (a.size() == 1) {cout << 0 << "\n"; return;}
    if ((a[0] + a[n-1]) % 2 == 0) {
        a[0] = a[n-1];
    }
    else {
        a[n-1] = a[0];
    }
    ans.push_back({1, n});
    for (int i = 1; i < n-1; i++) {
        if ((a[i] + a[0]) % 2 == 0) {
            ans.push_back({i+1, n});
        }
        else {
            ans.push_back({1, i+1});
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
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