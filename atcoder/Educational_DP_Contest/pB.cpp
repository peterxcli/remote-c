#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int N, K, h[100105]={0}, dp[100105];
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &h[i]);
        dp[i] = 1000000007;
    }
    dp[1] = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            dp[i+j] = min(dp[i]+abs(h[i+j]-h[i]), dp[i+j]);
        }
    }
    printf("%d\n", dp[N]);
}