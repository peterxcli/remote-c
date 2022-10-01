// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define MAXN 1000005
using namespace std;

void solve_subtask() {
    int n, ans = 0; cin >> n;
    string str; cin >> str;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) a[i] = str[i-1] - '0';
    for (int i = 1; i <= n; i++) {
        if (a[i] == 2) {
            for (int j = 2; i * j <= n; j++) {
                if (a[i*j] == 1) break;
                else if (a[i*j] == 0) {
                    ans += i;
                    a[i*j] = 2;
                }
            }
        }
        else if (a[i] == 0) {
            for (int j = 1; i * j <= n; j++) {
                if (a[i*j] == 1) break;
                else if (a[i*j] == 0) {
                    ans += i;
                    a[i*j] = 2;
                }
            }
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