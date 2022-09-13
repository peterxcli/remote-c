//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    int sum = 0;
    for (auto i:w) sum += i;
    if (sum == x) cout << "no\n";
    else {
        cout << "yes\n";
        int cur = 0;
        sort(w.begin(), w.end());
        for (int i = 0; i < n; i++) {
            if (cur + w[i] == x) swap(w[i], w[i+1]);
            cout << w[i] << " ";
            cur += w[i];
        }
        cout << "\n";
    }
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