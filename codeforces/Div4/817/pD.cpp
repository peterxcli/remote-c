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
    string str;
    cin >> str;
    int m = (n-1)/2;
    int l = 0, r = n-1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'L') ans += i;
        else ans += n-i-1;
    }
    // cout << "debug: " << ans << "\n";
    for (int i = 0; i < n; i++) {
        while (l != m+ (n%2==0) || r != m) {
            //cout << l << " " << n-r-1 << "\n";
            if (l != m+ (n%2==0) && l == n-r-1) {
                bool flag = 0;
                if (str[l] == 'L') {ans += (-l + n-l-1); flag = 1;}
                l++;
                if(flag) break;
            }
            if (r != m) {
                bool flag = 0;
                if (str[r] == 'R') {ans += (r - (n-r-1)); flag = 1;}
                r--;
                if (flag) break;
            }
        }
        cout << ans << " ";
    }
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