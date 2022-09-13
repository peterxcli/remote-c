#include <bits/stdc++.h>

using namespace std;
#define MAXN 10005
short m, dp[MAXN][MAXN];
int g(int x);

int main() {
    int N, k;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            dp[i][j] = -1;
        }
    }
    while (cin >> N && N != 0) {
        m = 2;
        k = g(N);
        for (m = N; m >= 0; m--) {
            if (m == 2) continue;
            else if (m == 0) cout << -1 << endl;
            else if(g(N) == k) {
                cout << m << endl;
                break;
            }
            
        }
    }
}

int g(int x) {
    if (x == 1) return 0;
    else if (dp[x-1][m] >= 0) return (dp[x-1][m]+m) % (x);
    else return dp[x][m] = (g(x-1)+m) % (x);
}