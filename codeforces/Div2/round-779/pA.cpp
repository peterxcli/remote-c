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
    string str;
    cin >> str;
    int ans = 0;
    for (int i = 0; i < str.size()-1; i++) {
        if (str[i] == '1') {
            int tmp;
            if (i == 0) continue;
            tmp = (str[i+1] == '1') + (str[i-1] == '1');
            if (tmp < 1) ans++;
        }
        else {
            if (str[i+1] == '0') ans += 2;
        }
    }
    cout << ans << endl;
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