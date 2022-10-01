// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    set<int> st;
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = k-1, r = k+1;
    int cur = a[k];
    int leftSum = 0, rightSum = 0, leftMax = 0, rightMax = 0;
    while (l >= 1 && r <= n) {
        if (cur + a[l] + rightMax + leftSum >= 0 || cur + a[r] + rightSum + leftMax >= 0) {
            if (cur + a[l] + rightMax + leftSum >= 0) {
                leftSum += a[l];
                l--;
                leftMax = max(leftMax, leftSum);
            }
            if (cur + a[r] + rightSum + leftMax >= 0) {
                rightSum += a[r];
                r++; 
                rightMax = max(rightMax, rightSum);
            }
        }
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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