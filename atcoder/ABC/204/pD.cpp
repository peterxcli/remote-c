
#include <iostream>
using namespace std;

#define MAXN 101
#define MAXSUM 100005
int A[MAXN];
bool dp[MAXN][MAXSUM];

// dp[k][s]表示从前k个数中取任意个数，且这些数之和为s的取法是否存在
int main() {
    int k, s, u, i, n;
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> A[i];
    int sum = 0;
    for (i = 1; i <= n; ++i)
        sum += A[i];
    dp[0][0] = true;
    // 阶段k表示第k个数
    for (k = 1; k <= n; ++k)
        // 注意状态可取0
        for (s = 0; s <= (sum >> 1); ++s) {
            // 加上第k个数,或不加它所能得到的和
            if (s >= A[k])
                dp[k][s] = dp[k - 1][s - A[k]] || dp[k - 1][s];
            else
                dp[k][s] = dp[k - 1][s];
        }
    for (s = (sum >> 1); s >= 1 && !dp[n][s]; --s);
    cout << sum - s << "\n";
}