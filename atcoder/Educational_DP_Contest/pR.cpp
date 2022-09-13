#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(3, "Ofast", "inline")
#define int long long
#define MAXN 55
int K, N;
const int MOD = 1000000007;
struct mat{
    int a[MAXN][MAXN];
    mat(){
        memset(a, 0, sizeof(a));
    }
    mat operator * (mat rhs){
        mat ret;
        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                for (int k = 1; k <= N; k++){
                    ret.a[i][j] = (ret.a[i][j] + a[i][k] * rhs.a[k][j]) % MOD;
                }
            }
        }
        return ret;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    mat unit;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> unit.a[i][j];
        }
    }
    mat ans = unit;
    for (int power = K - 1; power >= 1; power >>= 1, unit = unit * unit) {
        if (power & 1) ans = ans * unit;
    }
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sum = (sum + ans.a[i][j]) % MOD;
        }
    }
    cout << sum << "\n";
    return 0;
}