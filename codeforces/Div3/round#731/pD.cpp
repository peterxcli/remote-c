//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (auto &i : x) cin >> i;
    // for (auto i : x) cout << 0 << " ";
    vector<int> ans;
    ans.push_back(0);
    // int tmp = 0;
    for (int i = 1; i < x.size(); i++) {
        // tmp = max(tmp, (int)log2(x[i-1]&ans[i-1]));
        int k = (x[i-1]^ans[i-1]);
        if (x[i] > (x[i-1]^ans[i-1])) {
            int t = x[i], tmppp = 0;
            for (int base = 1; k; base *= 2, t >>= 1, k >>= 1) {
                if (!(k & 1)) {
                    tmppp += base;
                    break;
                }
                if (!(t & 1)) tmppp += base;
            }
            ans.push_back(tmppp);
        }
        else {
            int t = x[i], tmppp = x[i-1]^ans[i-1];
            for (int base = 1; t; base *= 2, t >>= 1) {
                if ((t & 1)) tmppp -= base;
            }
            ans.push_back(tmppp);
        }
    }
    for (auto i : ans) cout << i << " ";
    cout << "\n";
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