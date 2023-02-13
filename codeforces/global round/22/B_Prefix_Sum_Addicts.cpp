// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n, k; cin >> n >> k;
    vector<int> s(k);
    for (auto &x : s) cin >> x;
    for (int i = 1; i < k-1; i++) {
        if (s[i] - s[i-1] > s[i+1] - s[i]) {
            cout << "no\n";
            return;
        }
    }
    if (k == 1) {cout << "yes\n"; return;}
    int last = s[1] - s[0];
    int prev = (s[0] >= 0 ? s[0] / (n-k+1) + (s[0] % (n-k+1) != 0) : s[0] / (n-k+1));
    if (prev <= last) cout << "yes\n";
    else cout << "no\n";
    //a:  1    2     1
    //s:       3     4
    //   n-3  n-2   n-1
    //a: a1 a2 a3 -2 -2   
    //s:       -4 -6 -8
    //0 1
    //0 1
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