//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
const int mod = 1e9+7;
using namespace std;

int dp[1010][1010];
void solve_subtask() {
    memset(dp, 0, sizeof dp);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) dp[i][1] = 1;
    for (int i = 1; i <= k ;i++) dp[0][i] = 1;
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i <= n; i++) {
            //引用关系，需要先枚举j再枚举i进行处理。
            //从当前衰变年龄为最终态1开始从后往前倒推。
            //如果从还剩下一个平面开始倒推，就会产生错误。
            dp[i][j] = (dp[i-1][j] + dp[n-i][j-1]) % mod;
        }
    }
    cout << dp[n][k] << "\n";
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

// 设dp[i][j]为某个粒子前面还有i个平面，当前的衰变年龄为j。
// 每当向前移动一个平面，会产生一个衰变年龄减1（j-1）且方向相反（i=n-i）的粒子；
// 还会产生一个平面减1(i-=1)，衰变年龄不变(j=j)的粒子。
// 易得 dp[i][1] = 1（i=1~n），因为衰变年龄为1时不分裂。
// 同样的易得 dp[0][j] = 1（j=1~k），因为不经过平面也不分裂。
// 最终要求 dp[n][k] 