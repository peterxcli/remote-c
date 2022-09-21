// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n, cnt = 1; cin >> n;
    vector<int> nums;
    string a;
    cin >> a;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i-1]) nums.push_back(cnt), cnt = 1;
        else cnt++;
    }
    if (cnt) nums.push_back(cnt);
    int ans = 0;
    for (int i = 0; i < nums.size()-1; i++) {
        if (nums[i] & 1) nums[i]--, nums[i+1]++, ans++; 
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