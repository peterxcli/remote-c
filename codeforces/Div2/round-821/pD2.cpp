//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

#define MAXN 5005

int dp[MAXN];

void solve_subtask() {
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) dp[i] = 0;
    string a, b;
    vector<int> v;
    cin >> a >> b;
    for (int i = 0; i < n; i++) if (a[i] != b[i]) v.emplace_back(i);
    if (v.size() & 1) cout << -1 << "\n";
    else if (v.size() == 2) {
        if (v[0] + 1 == v[1]) cout << min(x, 2 * y) << "\n"; 
        else cout << y << "\n";
    }
    else {
        // dp[i] =  for (i \in [0, v[i].size()-1])
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v.size(); j++) {
                if (i == j) continue;
                dp[i] = min(dp[i] + dp[j], dp[i]);
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--)
    {
        solve_subtask();
    }
    return 0;
}