// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n, x, y;
    cin >> n >> x >> y;
    if (x == 0 && y == 0) {cout << -1 << "\n"; return;}
    if (x < y) swap(x, y);
    //int res = (n-1) - ((n-1)/(x+y)) * (x+y), a = (n-1)/(x+y);
    int cur = 1;
    
    if (y == 0 && (n-1) % x == 0) {
        for (int i = 0; i < (n-1) / x; i++) {
            for (int j = 0; j < x; j++) {
                cout << cur << " ";
            }
            cur += x+(cur == 1); 
        }
        cout << "\n";
    }
    else {
        cout << "-1\n";
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