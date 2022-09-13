//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int k, n , m;
    cin >> k >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    vector<int> ans;
    for (int i = 0; i < n+m; i++) {
        if (!a.empty() && a.front() == 0) {
            a.erase(a.begin(), a.begin()+1);
            ans.emplace_back(0);
            k++;
        }
        else if (!b.empty() && b.front() == 0) {
            b.erase(b.begin(), b.begin()+1);
            ans.emplace_back(0);
            k++;
        }
        else if (!a.empty() && a.front() <= k) {
            ans.emplace_back(a.front());
            a.erase(a.begin(), a.begin()+1);
        }
        else if (!b.empty() && b.front() <= k) {
            ans.emplace_back(b.front());
            b.erase(b.begin(), b.begin()+1);
        }
        else {
            cout << -1 << "\n";
            return;
        }
    }
    for (auto x : ans) cout << x << " ";
    cout << "\n";
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