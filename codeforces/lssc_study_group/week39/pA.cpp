#include <cstdio>

using namespace std;

int main() {
    int n, dp[105]={0};
    scanf("%d", &n);
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        dp[i] = dp[i-1]+4*i;
    }
    printf("%d\n", dp[n-1]);
}