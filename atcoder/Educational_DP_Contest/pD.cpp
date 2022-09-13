#include <bits/stdc++.h>
 
using namespace std;
 
int64_t N, W, w[110]={0}, v[110]={0}, dp[110][100100]={0};
 
int main() {
    
    scanf("%lld %lld", &N, &W);
    for (int64_t i = 0; i < N ; i++) 
        scanf("%lld %lld", &w[i], &v[i]);
    for (int64_t i = 0; i < N; i++) {
        for (int64_t j = 0; j <= W; j++) {
            if (j - w[i] < 0) {
                dp[i+1][j] = dp[i][j];
            }
            else {
                dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
            }
        }
    }
    printf("%lld\n", dp[N][W]);
}