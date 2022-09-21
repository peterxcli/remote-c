//codeforces template
// #define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n, Min = 0, max_amount = 0;
    cin >> n;
    map<int, int> mp;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a.begin(), a.end());
    for (auto x:mp) {
        if (x.second > max_amount) {
            max_amount = x.second;
            Min = x.first;
        }
        // else if (x.second == max_amount)
    }
    int ans = 0;
    for (auto x:a) {
        if (x == Min) continue;
        ans += abs(x-Min);
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
    while (cnt--)
    {
        solve_subtask();
    }
    return 0;
}