// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int dp[40004];
const int mod = 1e9 + 7;
vector<int> nums;
void solve_subtask() {
    int n;
    cin >> n;
    cout << dp[n] << "\n";
}
bool is_palindrome(int x) {
    string s = to_string(x);
    string t = s;
    reverse(t.begin(), t.end());
    return (s == t);
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    for (int i = 1; i <= 40004; i++) if (is_palindrome(i)) nums.push_back(i);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 1; j <= 40000; j++) {
            if (j - nums[i] >= 0) dp[j] = (dp[j] + dp[j-nums[i]]) % mod;
        }
    }
    while (cnt--) {
        solve_subtask();
    }
    return 0;
}