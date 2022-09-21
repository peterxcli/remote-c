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
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) tmp++;
    }
    for (int i = 0; i < n; i++) {
        if (tmp) a[i] = -abs(a[i]), tmp--;
        else a[i] = abs(a[i]);
    }
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            cout << "no\n";
            return;
        }
    }
    cout << "yes\n";
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