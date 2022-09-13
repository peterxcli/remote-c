#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
//#define int long long
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    
    return 0;
}

int dp[1005][1005], from[1005][1005]; //1:(i-1, j-1), 2:(i-1, j), 3:(i, j-1)
void solve() {
    int t;
    cin >> t;
    while (t--) {
        char a[1005], b[1005];
        cin >> a+1 >> b+1;
        int n = strlen(a), m = strlen(b);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i] == b[j]) {
                    dp[i][j] = dp[i-1][j-1];
                    from[i][j] = 1; //左上
                }
                else {
                    if (dp[i-1][j] > dp[i][j-1]) {
                        dp[i][j] = dp[i-1][j];
                        from[i][j] = 2; //上
                    }
                    else {
                        dp[i][j] = dp[i][j-1];
                        from[i][j] = 3; //左
                    }
                }
            }
        }

    }
}
