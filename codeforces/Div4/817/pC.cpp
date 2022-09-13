// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int ans[3];

void solve_subtask() {
    memset(ans, 0, sizeof ans);
    string in[3][1005];
    map<string, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {cin >> in[0][i]; mp[in[0][i]]++;}
    for (int i = 0; i < n; i++) {cin >> in[1][i]; mp[in[1][i]]++;}
    for (int i = 0; i < n; i++) {cin >> in[2][i]; mp[in[2][i]]++;}
    for (int i = 0 ; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            if (mp[in[i][j]] == 1) ans[i] += 3;
            if (mp[in[i][j]] == 2) ans[i]++;
        }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
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