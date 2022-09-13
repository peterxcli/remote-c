#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int N, h[100005]={0}, dp[100005]={0};
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &h[i]);
    dp[1] = 0;
    dp[2] = abs(h[2]-h[1]);
    for(int i = 3; i <= N; i++) {
        dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]), dp[i-2] + abs(h[i]-h[i-2]));
    }
    printf("%d\n", dp[N]);
}