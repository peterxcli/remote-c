//https://codeforces.com/problemset/problem/706/C
#include <bits/stdc++.h>
#define maxn 100005
#define inf (int)1e18
#define int long long
using namespace std;

int n, cost[maxn], dp[maxn][2];
string str[maxn][2];

int32_t main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> cost[i];
    for (int i = 0; i < n; i++) {
        cin >> str[i][0];
        str[i][1] = str[i][0];
        reverse(str[i][1].begin(), str[i][1].end());
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0;
    dp[0][1] = cost[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i][1] = inf;
        if (str[i][0] >= str[i-1][0]) dp[i][0] = min(dp[i][0], dp[i-1][0]);
        if (str[i][0] >= str[i-1][1]) dp[i][0] = min(dp[i][0], dp[i-1][1]);
        if (str[i][1] >= str[i-1][0]) dp[i][1] = min(dp[i][1], dp[i-1][0]+cost[i]);
        if (str[i][1] >= str[i-1][1]) dp[i][1] = min(dp[i][1], dp[i-1][1]+cost[i]);
    }
    int ans = min(dp[n-1][0], dp[n-1][1]);
    cout << (ans >= inf?-1:ans) << endl;
}