// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define lowbit(x) -x&x
using namespace std;
int n, a[500005], bit[500005], sum[500005], dp[500005], idx[500005];
void modify(int idx, int val) {
    for (int x = idx; x <= n; x += lowbit(x)) bit[x] = max(bit[x], val);
}

int query(int idx) {
    int ret = INT_MIN;
    for (int x = idx; x; x -= lowbit(x)) ret = max(bit[x], ret);
    return ret;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

void solve_subtask() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) bit[i] = INT_MIN, sum[i] = 0, dp[i] = 0;
    vector<pair<int, int> > v;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + a[i];
        v.emplace_back(sum[i], i);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 1; i <= n; i++) idx[v[i-1].second] = i;

    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) dp[i] = dp[i-1] + 1;
        else if (a[i] < 0) dp[i] = dp[i-1] - 1;
        else dp[i] = dp[i-1];
        dp[i] = max(dp[i], query(idx[i]) + i);
        if (sum[i] > 0) dp[i] = i;
        modify(idx[i], dp[i]-i); 
    }
    cout << dp[n] << "\n";
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