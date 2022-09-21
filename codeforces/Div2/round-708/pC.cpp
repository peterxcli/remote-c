//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void ans(int n, int k) {
    if (n%k == 0) cout << n/3 << " " << n/3 << " " << n-(n/3)*2;
    else if (n%4 == 0) cout << n/2 << " " << n/4 << " " << n/4;
    else if (n%2 == 1) cout << 1 << " " << n/2 << " " << n/2;
    else if (n%2 == 0) cout << 2 << " " << (n)/2-1 << " " << (n)/2-1;
}
void solve_subtask() {
    int n, k;
    cin >> n >> k;
    ans(n-k+3, 3);
    for (int i = 3; i < k; i++) cout << " 1";
    cout << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--)
    {
        solve_subtask();
    }
    return 0;
}