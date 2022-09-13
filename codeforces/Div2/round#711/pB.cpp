//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define MAXW 1000010
using namespace std;
map<int, int> num;
void solve_subtask() {
    num.clear();
    int n, w, tmp;
    cin >> n >> w;
    // vector<int> boxes(n);
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        num[tmp]++;
    }
    int ans = 1, remain = w;
    while(n--) {
        tmp = pow(2, floor(log2(remain)));
        // cout << pow(2, floor(log2(remain))) << "\n";
        if (tmp != 1 && tmp&1) tmp--;
        while(num[tmp] == 0) {
            // cout << "QQ\n";
            tmp >>= 1;
            if (tmp == 0) {
                ans++;
                remain = w;
                tmp = pow(2, floor(log2(remain)));
            }
        }
        num[tmp]--;
        remain -= tmp;
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