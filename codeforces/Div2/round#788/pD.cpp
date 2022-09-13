// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

vector<int> ans;

void solve_subtask() {
    int n; cin >> n;
    cout << lower_bound(ans.begin(), ans.end(), n) - ans.begin() << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    int k = 2;
    ans.emplace_back(0);
    ans.emplace_back(0);
    ans.emplace_back(2);
    ans.emplace_back(4);
    while (ans.back() < 100000) {
        vector<int> tmp(3, 0);
        tmp[0] = (k) * 2;
        tmp[1] = (k+1) * 2;
        tmp[2] = (k+2) * 2;
        ans.emplace_back(tmp[0]);
        ans.emplace_back(tmp[1]);
        ans.emplace_back(tmp[2]);
        k += 2;
    }
    for (int i = 1; i < ans.size(); i++) ans[i] = ans[i-1] + ans[i];
    // cout << ans.back();
    while (cnt--) {
        solve_subtask();
    }
    return 0;
}