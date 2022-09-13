// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
void solve_subtask() {
    int n;
    cin >> n;
    int ori = 0, alt = 0;
    for (int i = 0; i < n-2; i++) {
        ori ^= i;
        alt ^= (i+1);
    }
    int factor = 2<<28;
    if (ori != 0) {
        for (int i = 0; i < n-2; i++) cout << i << " ";
        cout << factor << " " << (factor ^ ori) << "\n";
    }
    else {
        for (int i = 0; i < n-2; i++) cout << i+1 << " ";
        cout << factor << " " << (factor ^ alt) << "\n";
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