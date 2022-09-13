// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int a[200005], b[200005], c[200005];
void solve_subtask() {
    memset(c, 0, sizeof c);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int i = 0, j = 0;
    while (j < n) {
        if (i < n && j < n && a[i] == b[j])
            i++, j++;
        else if (j > 0 && c[b[j]] && b[j] == b[j - 1])
            c[b[j]]--, j++;
        else if (i < n)
            c[a[i]]++, i++;
        else {
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