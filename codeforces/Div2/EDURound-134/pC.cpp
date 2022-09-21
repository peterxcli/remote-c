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
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (int i = 0; i < n; i++) {
        cout << *lower_bound(b.begin(), b.end(), a[i]) - a[i] << (i == n-1 ? "\n" : " ");
    }
    vector<int> mx(n);
    int j = n;
    for (int i = n-1; i >= 0; i--) {
        int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        mx[i] = b[j-1] - a[i];
        if (pos == i) j = i;
    }
    for (int i = 0; i < mx.size(); i++) cout << mx[i] << (i == n-1 ? "\n" : " ");
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