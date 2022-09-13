// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define lowbit(x) x &(-x)
#define endl '\n'
#define int long long
using namespace std;
int cnt[5005], n, a[5005], sum[5005];

void solve_subtask() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] > a[j]) cnt[i]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] > a[i]) cnt[j]--;
        }
        for (int j = 1; j <= i; j++) sum[j] = sum[j - 1] + cnt[j];
        for (int j = 1; j < i; j++) { if (a[j] < a[i]) ans += sum[i - 1] - sum[j];
        }
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